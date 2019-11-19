/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_outils.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/17 17:03:32 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 15:54:07 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/libft.h"

void		ft_end_one_check(t_bool *struc)
{
	struc->arg = NULL;
	free(struc);
	struc = NULL;
}

t_bool		*ft_set_struct(t_bool *struc)
{
	if (!(struc = malloc(sizeof(*struc))))
		return (NULL);
	struc->pre = 0;
	struc->zero = 0;
	struc->pre_star = 0;
	struc->arg = NULL;
	struc->str = NULL;
	return (struc);
}
