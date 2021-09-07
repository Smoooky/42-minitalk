#include "../includes/ft_printf.h"

int	ft_print_zero(t_print *tab)
{
	int	ret;

	ret = 0;
	if (tab->altfmt == 1)
		tab->length -= 2;
	if (tab->length > 0)
	{
		while (--tab->length >= 0)
		{
			ft_putchar_fd(tab->padc, 1);
			ret++;
		}
	}
	if (tab->altfmt == 1)
	{
		write(1, "0x", 2);
		ret += 2;
	}
	return (ret);
}

int	ft_print_nullterm(t_print *tab)
{
	int	ret;

	ret = 0;
	while (--tab->length >= 1 && tab->ladjust == -1)
	{
		ft_putchar_fd(tab->padc, 1);
		ret++;
	}
	ft_putchar_fd('\0', 1);
	ret++;
	while (--tab->length >= 0 && tab->ladjust == 1)
	{
		ft_putchar_fd(tab->padc, 1);
		ret++;
	}
	return (ret);
}

void	ft_initialise_tab(t_print *tab)
{
	tab->length = 0;
	tab->prec = -1;
	tab->ladjust = -1;
	tab->padc = ' ';
	tab->sign_char = 0;
	tab->altfmt = -1;
	tab->base = 10;
	tab->capitals = 0;
}
