#include "../includes/ft_printf.h"

int	ft_printf_signed(t_print *tab, va_list *argp)
{
	long			n;
	unsigned long	u;

	n = va_arg(*argp, int);
	if (n >= 0)
		u = n;
	else
	{
		u = -n;
		tab->sign_char = '-';
	}
	return (ft_printf_num(tab, u));
}

int	ft_printf_usigned(t_print *tab, va_list *argp)
{
	unsigned long	u;

	u = 0;
	if (tab->altfmt == 1)
		u = va_arg(*argp, unsigned long);
	else
		u = (unsigned long)va_arg(*argp, unsigned int);
	return (ft_printf_num(tab, u));
}

int	ft_printf_num(t_print *tab, unsigned long u)
{
	char			buf[(sizeof(long int) * 8)];
	register char	*p;
	static char		digits[] = "0123456789abcdef0123456789ABCDEF";
	int				ret;

	if (u == 0 && tab->prec == 0)
		return (ft_print_zero(tab));
	ret = 0;
	p = &buf[(sizeof(long int) * 8) - 1];
	*p-- = digits[(u % tab->base) + tab->capitals];
	u /= tab->base;
	while (u != 0)
	{
		*p-- = digits[(u % tab->base) + tab->capitals];
		u /= tab->base;
	}
	tab = ft_len_prec_count(tab, &buf[(sizeof(long int) * 8) - 1] - p);
	ret += ft_printf_before_num(tab);
	while (++p != &buf[(sizeof(long int) * 8)])
	{
		ft_putchar_fd(*p, 1);
		ret++;
	}
	ret += ft_printf_after_num(tab);
	return (ret);
}
