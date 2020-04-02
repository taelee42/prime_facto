/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelee <taelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:55:18 by taelee            #+#    #+#             */
/*   Updated: 2020/04/02 22:39:55 by taelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

long long		ft_atoi(const char *str)
{
	long long number;

	number = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			number = number * 10 + *str - '0';
		str++;
	}
	return (number);
}

void			ft_putnbr(unsigned int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void			ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void			ft_error_msg(char *msg)
{
	ft_putstr(msg);
	exit (1);
}

int				ft_digit_len(char *str)
{
	int len;
	
	while (*str && *str == '0')
		str++;
	len = 0;
	while(*str)
	{
		str++;
		len++;
	}
	return (len);
}

unsigned int	ft_error_handle(int argc, char **argv)
{
	long long	n;
	int			i;

	if (argc != 2)
		ft_error_msg("Enter only one argument\n");
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			ft_error_msg("Enter only a positive number\n");
		i++;
	}
	if (ft_digit_len(argv[1]) > 10)
			ft_error_msg("Enter a number less than or equal to 4294967295 (= 2^32-1)\n");
	n = ft_atoi(argv[1]);
	if (n > 4294967295)
			ft_error_msg("Enter a number less than or equal to 4294967295 (= 2^32-1)\n");
	if (n < 2)
			ft_error_msg("Enter a number greater than or equal to 2\n");
	return ((unsigned int)n);
}

unsigned int	ft_even_to_odd(unsigned n)
{
	int occurred_before;

	occurred_before = 0;
	while (n % 2 == 0)
	{
		if (occurred_before == 0)
		{
			ft_putnbr(2);
			write(1, " ", 1);
		}
		occurred_before = 1;
		n = n / 2;
	}
	return (n);
}

void			ft_prime_factors(unsigned int n)
{
	unsigned int	i;
	int				occurred_before;
	
	i = 3;
	while (i * i <= n)
	{
		occurred_before = 0;
		while (n % i == 0)
		{
			if (occurred_before == 0)
			{
				ft_putnbr(i);
				write(1, " ", 1);
			}
			occurred_before = 1;
			n = n / i;
		}
		i += 2;
	}
	if (n > 2)
		ft_putnbr(n);
}

int				main(int argc, char **argv)
{
	unsigned int n;

	n = ft_error_handle(argc, argv);
	n = ft_even_to_odd(n);
	ft_prime_factors(n);
	write(1, "\n", 1);
}
