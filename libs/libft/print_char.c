/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:49:25 by mrechuli          #+#    #+#             */
/*   Updated: 2024/05/28 17:33:58 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

// int main(void)
// {
//     char c = '0';
// 	printf(" Dlugosc: %d", print_char(c));
//     return (0);
// }