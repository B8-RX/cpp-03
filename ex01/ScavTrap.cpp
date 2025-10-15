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

ScavTrap::ScavTrap(void) : _name("noName"), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
	std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
	std::cout << "ScavTrap Name constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	std::cout << "ScavTrap Copy constructor called\n";	
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap Copy assignement operator called\n";	
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " has no hit points or energy left. Cannot attack!\n";
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap Gate keeper mode activated\n";
}
