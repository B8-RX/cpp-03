/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 03:22:08 by ssghioua          #+#    #+#             */
/*   Updated: 2025/10/13 03:22:11 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	player1("john");

	player1.attack("bob");
	player1.takeDamage(3);
	player1.beRepaired(2);
	return (0);
}
