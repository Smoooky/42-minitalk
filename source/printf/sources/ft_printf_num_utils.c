#include "../includes/ft_printf.h"

t_print	*ft_len_prec_count(t_print *tab, int a)
{
	tab->length -= a;
	if (tab->sign_char != 0)
		tab->length--;
	if (tab->prec >= 0)
	{
		tab->prec -= a;
		if (tab->prec >= 0)
			tab->length -= tab->prec;
	}
	return (tab);
}

int	ft_printf_before_num(t_print *tab)
{
	int	ret;

	ret = ft_printf_before_num_sub(tab);
	if (tab->altfmt == 1)
	{
		write(1, "0x", 2);
		ret += 2;
	}
	if (tab->ladjust == -1 && tab->padc == '0')
	{
		while (--tab->length >= 0)
		{
			ft_putchar_fd(tab->padc, 1);
			ret++;
		}
	}
	while (--tab->prec >= 0)
	{
		ft_putchar_fd('0', 1);
		ret++;
	}
	return (ret);
}

int	ft_printf_before_num_sub(t_print *tab)
{
	int	ret;

	ret = 0;
	if (tab->altfmt == 1)
		tab->length -= 2;
	if (tab->ladjust == -1 && tab->padc == ' ')
	{
		while (--tab->length >= 0)
		{
			ft_putchar_fd(tab->padc, 1);
			ret++;
		}
	}
	if (tab->sign_char)
	{
		ft_putchar_fd(tab->sign_char, 1);
		ret++;
	}
	return (ret);
}

int	ft_printf_after_num(t_print *tab)
{
	int	ret;

	ret = 0;
	if (tab->ladjust == 1)
	{
		while (--tab->length >= 0)
		{
			ft_putchar_fd(' ', 1);
			ret++;
		}
	}
	return (ret);
}
