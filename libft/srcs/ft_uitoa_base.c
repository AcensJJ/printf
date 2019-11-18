/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uitoa_base.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 06:29:53 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 14:22:35 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_config_ptr2(unsigned long long nb, unsigned long long i,
								char *ptr, char *base)
{
	long long			reste;
	long long			j;
	unsigned long long	len;

	j = -1;
	len = i;
	while (nb >= i)
		i *= len;
	while (i >= len)
	{
		i /= len;
		reste = nb % i;
		ptr[++j] = base[((nb - reste) / i)];
		nb = reste;
	}
	ptr[++j] = 0;
}

static int		ft_ucount_nbr_base(unsigned long long n, unsigned long long len)
{
	unsigned long long	i;
	long long			count;

	count = 1;
	i = len;
	while (n >= i)
	{
		i *= len;
		count++;
	}
	return (count);
}

char			*ft_uitoa_base(void *n, char *base)
{
	char					*ptr;
	unsigned long long		nb;
	unsigned long long		i;

	nb = (unsigned long long)n;
	i = ft_strlen(base);
	if (!(ptr = malloc(ft_ucount_nbr_base(nb, i) + 1)))
		return (NULL);
	*ptr = 0;
	ft_config_ptr2(nb, i, ptr, base);
	return (ptr);
}
