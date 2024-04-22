/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:50 by claprand          #+#    #+#             */
/*   Updated: 2024/04/22 17:21:50 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(va_list	*arg, char *s, int i)
{
	int	len;

	len = 0;
	if (s[i] == 'c')
		len = ft_print_char((int)va_arg(*arg, int));
	else if (s[i] == 's')
		len = ft_print_str((char *)va_arg(*arg, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		len = ft_print_int((int)va_arg(*arg, int));
	else if (s[i] == 'x')
		len = ft_print_x((unsigned int)va_arg(*arg, unsigned int), s[i], &len);
	else if (s[i] == 'X')
		len = ft_printux((unsigned int)va_arg(*arg, unsigned int), s[i], &len);
	else if (s[i] == 'p')
	{
		ft_putstr_fd("0x", 1);
		len = 2 + ft_print_p((void *)va_arg(*arg, void *), &len);
	}
	else if (s[i] == 'u')
		len = ft_print_u((unsigned int)va_arg(*arg, unsigned int));
	else if (s[i] == '%')
		len = ft_print_percent((int)va_arg(*arg, int));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = -1;
	len = 0;
	va_start(arg, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_print_conversion(&arg, (char *)s, i);
			continue ;
		}
		else
			len += ft_print_char(s[i]);
	}
	va_end(arg);
	return (len);
}

// #include <limits.h>
// int main()
// {   
//     int addr = -1;
    
//     int res = printf(" %p ", &addr);
//     printf("\n");
//     int res2 = ft_printf(" %p ", &addr);
//     printf("\n");
//     printf("pf : %d VS mypf : %d", res, res2);
//     printf("\n");
//     printf("\n");

//     int addr1 = 1;
    
//     int res3 = printf(" %p ", &addr1);
//     printf("\n");
//     int res4 = ft_printf(" %p ", &addr1);
//     printf("\n");
//     printf("pf : %d VS mypf : %d", res3, res4);
//     printf("\n");
//     printf("\n");


//     int addr2 = 15;
    
//     int res5 = printf(" %p ", &addr2);
//     printf("\n");
//     int res6 = ft_printf(" %p ", &addr2);
//     printf("\n");
//     printf("pf : %d VS mypf : %d", res5, res6);
//     printf("\n");
//     printf("\n");
    
//     int addr3 = 16;
    
//     int res7 = printf(" %p ", &addr3);
//     printf("\n");
//     int res8 = ft_printf(" %p ", &addr3);
//     printf("\n");
//     printf("pf : %d VS mypf : %d", res7, res8);
//     printf("\n");
//     printf("\n");
    
//     int addr4 = 17;
    
//     int res9 = printf(" %p ", &addr4);
//     printf("\n");
//     int res10 = ft_printf(" %p ", &addr4);
//     printf("\n");
//     printf("pf : %d VS mypf : %d", res9, res10);
//     printf("\n");
//     printf("\n");
    
//     long long addr5 = LONG_MIN;
//     unsigned long long addr6 = LONG_MAX;
//     int res11 = printf(" %p %p ", &addr5, &addr6);
//     printf("\n");
//     int res12 = ft_printf(" %p %p ", &addr4, &addr5);
//     printf("\n");
//     printf("pf : %d VS mypf : %d", res11, res12);
//     printf("\n");
//     printf("\n");
    
//     int addr7 = INT_MIN;
//     int addr8 = INT_MAX;
//     int res13 = printf(" %p %p ", &addr7, &addr8);
//     printf("\n");
//     int res14 = ft_printf(" %p %p ", &addr7, &addr8);
//     printf("\n");
//     printf("pf : %d VS mypf : %d", res13, res14);
//     printf("\n");
//     printf("\n");
    

//     unsigned long long addr9 = ULONG_MAX;
//     long long addr10 = -ULONG_MAX;
//     int res15 = printf(" %p %p ", &addr9, &addr10);
//     printf("\n");
//     int res16 = ft_printf(" %p %p ", &addr9, &addr10);
//     printf("\n");
//     printf("pf : %d VS mypf : %d", res15, res16);
//     printf("\n");
//     printf("\n");
    
//     int addr11 = 0;
//     int addr12 = 0;
//     int res17 = printf(" %p %p ", &addr11, &addr12);
//     printf("\n");
//     int res18 = ft_printf(" %p %p ", &addr11, &addr12);
//     printf("\n");
//     printf("pf : %d VS mypf : %d", res17, res18);
//     printf("\n");
//     printf("\n");
// }