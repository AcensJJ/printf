/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pre_cas_d_3.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:55:46 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 21:42:17 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

void	ft_cas_d_1(t_bool *struc, char *ptr, int *valprintf)
{
	if (struc->space > 1 && struc->zero == -1
	&& (ft_strcmp(ptr, "0") == 0) && struc->left != 1 && struc->dot != 1)
	{
		struc->space < 0 ? struc->left = 1 : 0;
		struc->space < 0 ? struc->space *= -1 : 0;
		struc->zero < 0 && struc->print < 0 ? struc->print = 0 : 0;
		struc->zero < 0 ? struc->zero = 0 : 0;
		ptr[0] == '-' ? struc->zero += 1 : 0;
		struc->print == -1 ? struc->print = (int)ft_strlen(ptr) : 0;
		struc->zero -= struc->print;
		struc->zero < 0 ? struc->zero = 0 : 0;
		struc->space -= (struc->print + struc->zero);
		struc->space -= ft_strlen(ptr);
		struc->print = ft_strlen(ptr);
	}
	else if (struc->space == 1 && struc->zero == -1
	&& (ft_strcmp(ptr, "0") == 0) && struc->left != 1 && struc->dot != 1)
	{
		struc->space -= ft_strlen(ptr);
	}
	else
		ft_cas_d_1_2(struc, ptr, valprintf);
}

void	ft_cas_d_1_2(t_bool *struc, char *ptr, int *valprintf)
{
	if (struc->space > 0 && struc->zero == -1
	&& (ft_strcmp(ptr, "0") == 0) && struc->left != 1 && struc->dot == 1)
	{
		struc->space < 0 ? struc->left = 1 : 0;
		struc->space < 0 ? struc->space *= -1 : 0;
		struc->zero < 0 && struc->print < 0 ? struc->print = 0 : 0;
		struc->zero < 0 ? struc->zero = 0 : 0;
		ptr[0] == '-' ? struc->zero += 1 : 0;
		struc->print == -1 ? struc->print = (int)ft_strlen(ptr) : 0;
		struc->zero -= struc->print;
		struc->zero < 0 ? struc->zero = 0 : 0;
		struc->space -= (struc->print + struc->zero);
	}
	else
		ft_cas_d_1bis(struc, ptr, valprintf);
}

void	ft_cas_d_11(t_bool *struc, char *ptr, int *valprintf)
{
	if (struc->space == 1 && struc->zero == 1
	&& (ft_strcmp(ptr, "0") == 0) && struc->dot == 1)
	{
		write(1, "0", 1);
		struc->space = 0;
		struc->zero = 0;
		struc->print = 1;
		*valprintf += 1;
	}
	else
		ft_cas_d_12(struc, ptr);
}

void	ft_cas_d_12(t_bool *struc, char *ptr)
{
	if (!(struc->space == 0 && struc->zero == 0
	&& (ft_strcmp(ptr, "0") == 0)))
	{
		struc->space < 0 ? struc->left = 1 : 0;
		struc->space < 0 ? struc->space *= -1 : 0;
		struc->zero < 0 && struc->print < 0 ? struc->print = 0 : 0;
		struc->zero < 0 ? struc->zero = 0 : 0;
		ptr[0] == '-' ? struc->zero += 1 : 0;
		struc->print == -1 ? struc->print = (int)ft_strlen(ptr) : 0;
		struc->zero -= struc->print;
		struc->zero < 0 ? struc->zero = 0 : 0;
		struc->space -= (struc->print + struc->zero);
		if (struc->print == 0 && struc->space != -1)
		{
			struc->space -= ft_strlen(ptr);
			struc->print = ft_strlen(ptr);
		}
	}
}
