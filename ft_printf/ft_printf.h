/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <rloussig@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:35:50 by rloussig          #+#    #+#             */
/*   Updated: 2023/02/28 17:35:52 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putstr_nbr(char *str, int nbr, int l);
void	ft_rev_int_tab(char *tab, int size);
int		ft_putnbr_hex_ul(unsigned long nb2);
int		ft_putnbr_hex_int(unsigned int nb2, char cap);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putnbr_signed(int nb);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putstr_nbr(char *str, int nbr, int l);
int		ft_print_arg(va_list arg, char type);

#endif
