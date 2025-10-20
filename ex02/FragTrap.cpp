/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 05:08:39 by ssghioua          #+#    #+#             */
/*   Updated: 2025/10/17 05:08:40 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap [" << _name << "] Default constructor called\n";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap [" << _name << "] Destructor called\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap [" << _name << "] Name constructor called\n";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	if (this != &other)
	{
		_name = other._name; 
		_hitPoints = 100;
		_energyPoints = 100;
		_attackDamage = 30;
	}
	std::cout << "FragTrap [" << _name << "] Copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "FragTrap [" << _name << "] Copy assignment operator called\n";
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap [" << _name << "] High Five!\n";
}
