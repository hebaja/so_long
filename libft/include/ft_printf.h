/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:13:58 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/17 20:14:02 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_putchar_len(char c);
int		ft_putstr_len(char *str);
int		print_type(const char *str, va_list args);
int		ft_printf(const char *str, ...);
void	ft_putnbr_base_len(long nbr, char *base, int *len);
void	ft_putptr_base_len(unsigned long nbr, char *base, int *len);

#endif
