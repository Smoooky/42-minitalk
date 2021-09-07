#include "../includes/ft_printf.h"

int	ft_printf_str(t_print *tab, register char *p)
{
	long			n;
	int				ret;

	if (tab->prec <= -1)
		tab->prec = 0x7fffffff;
	ret = ft_printf_before_str(tab, p);
	n = 0;
	while (*p != '\0')
	{
		if (++n > tab->prec)
		{
			n--;
			break ;
		}
		ft_putchar_fd(*p++, 1);
		ret++;
	}
	ret += ft_printf_after_str(tab, n);
	return (ret);
}

int	ft_printf_after_str(t_print *tab, long	n)
{
	int	ret;

	ret = 0;
	if (n < tab->length && tab->ladjust == 1)
	{
		while (n++ < tab->length)
		{
			ft_putchar_fd(tab->padc, 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_printf_before_str(t_print *tab, register char *p)
{
	long			n;
	int				ret;

	ret = 0;
	n = 0;
	if (tab->length > 0 && tab->ladjust == -1)
	{
		while (*p != '\0' && n < tab->prec)
		{
			n++;
			p++;
		}
		while (n < tab->length)
		{
			ft_putchar_fd(tab->padc, 1);
			ret++;
			n++;
		}
	}
	return (ret);
}
