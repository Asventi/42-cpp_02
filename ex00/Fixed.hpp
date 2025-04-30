/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:36:41 by pjarnac           #+#    #+#             */
/*   Updated: 2025/04/30 16:36:41 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	static const int	bits;
	int					_value;

public:
	int		getRawBits() const;
	void	setRawBits(int const raw);

	Fixed();
	~Fixed();
	Fixed(const Fixed &cpy);
	Fixed &operator=(const Fixed &e);
};

#endif
