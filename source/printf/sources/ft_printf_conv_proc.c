#include "../includes/ft_printf.h"

int	ft_conv_proc(t_print *tab, register const char *format, va_list *argp)
{
	register char	c;
	char			st[2];

	c = *format;
	if (c == 'c')
	{
		c = va_arg(*argp, long int);
		if (c == '\0')
			return (ft_print_nullterm(tab));
		st[0] = c;
		st[1] = 0;
		return (ft_printf_str(tab, st));
	}
	if (c == '%')
		return (ft_printf_str(tab, "%"));
	if (c == 's')
		return (ft_str_conv(tab, argp));
	if (c == 'd' || c == 'i')
		return (ft_printf_signed(tab, argp));
	if (c == 'u' || c == 'p' || c == 'x' || c == 'X')
		return (ft_num_conv(tab, c, argp));
	return (0);
}

int	ft_str_conv(t_print *tab, va_list *argp)
{
	char			*str;

	str = va_arg(*argp, char *);
	if (str != NULL)
		return (ft_printf_str(tab, str));
	else
		return (ft_printf_str(tab, "(null)"));
}

int	ft_num_conv(t_print *tab, register char	c, va_list *argp)
{
	if (c == 'x')
		tab->base = 16;
	else if (c == 'X')
	{
		tab->base = 16;
		tab->capitals = 16;
	}
	else if (c == 'p')
	{
		tab->base = 16;
		tab->altfmt = 1;
	}
	return (ft_printf_usigned(tab, argp));
}
