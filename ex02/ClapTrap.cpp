/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 03:22:49 by ssghioua          #+#    #+#             */
/*   Updated: 2025/10/13 03:22:50 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <limits>

ClapTrap::ClapTrap(void) : _name("noName"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap [" << _name << "] Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap [" << _name << "] Name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap [" << _name << "] Copy constructor called\n";	
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap [" << _name << "] Copy assignement operator called\n";	
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap [" << _name << "] Destructor called\n";
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap [" << _name << (_hitPoints <= 0 ? "] is already destroyed!" : "] has no energy left.") << " Cannot attack!\n";
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap [" << _name << "] attacks " << target << ", causing " << _attackDamage << " points of damage! Energy left: " << _energyPoints << "\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap [" << _name << "] is already destroyed!\n";
		return ;
	}
	int dmg = (amount > static_cast<unsigned int>(_hitPoints) ? _hitPoints : static_cast<int>(amount));
	_hitPoints -= dmg;
	std::cout << "ClapTrap [" << _name << "] takes "<< (dmg == _hitPoints ? dmg : amount) << " points of damage. Current HP: " << _hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap [" << _name << (_hitPoints <= 0 ? "] is already destroyed!" : "] has no energy left.") << " Cannot repair!\n";
		return ;
	}
	_energyPoints--;
	if (static_cast<int>(amount) > (std::numeric_limits<int>::max() - _hitPoints))
		_hitPoints = std::numeric_limits<int>::max();
	else
		_hitPoints += amount;
	std::cout << "ClapTrap [" << _name << "] Repairs itself by " << amount << " hit points. Current HP: " << _hitPoints << ". Energy left: " << _energyPoints << "\n";
}
