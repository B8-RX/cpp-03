/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 01:34:25 by ssghioua          #+#    #+#             */
/*   Updated: 2025/10/15 01:34:26 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap [" << _name << "] Default constructor called\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap [" << _name << "] Name constructor called\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ScavTrap [" << _name << "] Copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "ScavTrap [" << _name << "] Copy assignment operator called\n";
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap [" << _name << "] Destructor called\n";
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ScavTrap [" << _name << "] has no hit points or energy left. Cannot attack!\n";
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap [" << _name << "] attacks " << target << ", causing " << _attackDamage << " points of damage! Energy left: " << _energyPoints << "\n";
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap [" << _name << "] is now on [Gate keeper] mode!\n";
}
