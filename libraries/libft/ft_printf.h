/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:29:25 by cvallejo          #+#    #+#             */
/*   Updated: 2022/08/10 13:40:27 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

//ft_printf functions
int		ft_printf(char const *str, ...);
int		ft_format_check(char const str, va_list things);

//printchar functions
int		ft_format_char(int c);
int		ft_format_str(char *s);
int		ft_format_dec(long num);

//print_hexa
int		ft_format_ptr(unsigned long long ptr);
int		ft_hexabase(unsigned long long num, int flag);

//print_dec
int		ft_format_dec(long num);
int		ft_count_dec(long num);
int		ft_format_undec(long num);

//printf_utils functions
int		ft_strlen_pf(char *ptr);
void	ft_putchar(int c);
void	ft_putstr_pf(char *s);

#endif
