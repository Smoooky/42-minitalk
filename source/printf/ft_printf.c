#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_print	*tab;
	va_list	vl;

	ret = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(vl, format);
	ret = ft_eval_format(tab, format, &vl);
	va_end(tab->arg);
	free(tab);
	return (ret);
}

int	ft_eval_format(t_print *tab, register const char *format, va_list *argp)
{
	register char	c;
	int				ret;

	ret = 0;
	c = *format;
	while (c != '\0')
	{
		if (c != '%')
		{
			ft_putchar_fd(c, 1);
			ret++;
		}
		else
		{
			ft_initialise_tab(tab);
			format = ft_ladj_padc(&tab, format);
			format = ft_len(&tab, format, argp);
			format = ft_prec(&tab, format, argp);
			ret += ft_conv_proc(tab, format, argp);
		}
		c = *++format;
	}
	return (ret);
}

const char	*ft_ladj_padc(t_print **tab, register const char *format)
{
	register char	c;

	c = *++format;
	if (c == '-')
	{
		(*tab)->ladjust = 1;
		c = *++format;
	}
	if (c == '0')
	{
		if ((*tab)->ladjust != 1)
			(*tab)->padc = '0';
		c = *++format;
	}
	if (c == '-')
	{
		(*tab)->ladjust = 1;
		++format;
	}
	return (format);
}

const char	*ft_len(t_print **tab, register const char *format, va_list *argp)
{
	register char	c;

	c = *format;
	if (ft_isdigit(c))
	{
		while (ft_isdigit(c))
		{
			(*tab)->length = 10 * (*tab)->length + (c - '0');
			c = *++format;
		}
	}
	if (c == '*')
	{
		(*tab)->length = va_arg(*argp, int);
		++format;
		if ((*tab)->length < 0)
		{
			(*tab)->ladjust = 1;
			(*tab)->length = (*tab)->length * -1;
		}
		if ((*tab)->padc == '0' && (*tab)->ladjust == 1)
			(*tab)->padc = ' ';
	}
	return (format);
}

const char	*ft_prec(t_print **tab, register const char *format, va_list *argp)
{
	register char	c;

	c = *format;
	if (c == '.')
	{
		(*tab)->prec = 0;
		(*tab)->padc = ' ';
		c = *++format;
		if (ft_isdigit(c))
		{
			while (ft_isdigit(c))
			{
				(*tab)->prec = 10 * (*tab)->prec + (c - '0');
				c = *++format;
			}
		}
		else if (c == '*')
		{
			(*tab)->prec = va_arg(*argp, int);
			++format;
		}
	}
	return (format);
}
