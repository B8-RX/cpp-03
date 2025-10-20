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

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

void	test_name(std::string msg) {
	std::cout << "\n\n=========== " << msg << " ============\n"; 
}

int	main(void)
{
	ClapTrap	clap("john doe");
	ClapTrap	trap("toto");

	test_name("should not repair after taking 42 points of damages, and display '...is already destroyed! Cannot repair!'");
	clap.attack("bob");
	clap.takeDamage(42);
	clap.beRepaired(10);

	test_name("should not attack after 10 times, and display '...no energy left. Cannot attack!'");
	for (int i = 0; i <= 10; i++)
		trap.attack("foo");
	
	test_name("should not take damage after 10 times, and display the message '...already destroyed!'");
	for (int i = 0; i <= 10; i++)
		trap.takeDamage(1);

	test_name("coplien");
	ClapTrap	a("alpha");
	ClapTrap	b = a;
	ClapTrap	c("charlie");

	c = a;

	test_name("ClapTrap 'c' should have as name 'alpha' and have energy points equal to 9 after the attack");
	c.attack("bob");

	b.takeDamage(5);
	test_name("ClapTrap 'b' should have as name 'alpha' and after repaired itself 'alpha' should have hit points equal to 6.");
	b.beRepaired(1);

	test_name("hit points should not be on Int overflow");
	b.beRepaired(2147483647);

	test_name("hit points should be 9.");
	a.takeDamage(1);
	
	ClapTrap	unknown;

	test_name("should display 'no_name' as name and should not be able to repair after the second takeDamage() call");
	unknown.attack("bar");
	unknown.takeDamage(9);
	unknown.beRepaired(1);
	unknown.takeDamage(9);
	unknown.beRepaired(1);

	test_name("INHERITANCE");
	test_name("should display the constructor message of ClapTrap then the ScavTrap one");
	ScavTrap	x("mum");

	test_name("ScavTrap should be able to use the methods inherited from the base class ClapTrap with the new initialized values");
	x.attack("bruh");
	x.takeDamage(5);
	x.beRepaired(5);

	test_name("ScavTrap should be able to use the guardGate() and informing that he is on Gate keeper mode");
	x.guardGate();

	test_name("Coplien");
	test_name("ScavTrap 'y' should be created with Name constructor");
	ScavTrap	y("dad");

	test_name("ScavTrap 'z' shoud copy 'y' by calling Copy constructor");
	ScavTrap	z = y;
	z.attack("villain");

	test_name("ScavTrap 'soso' should call Default constructor and his _name is 'noName'");
	ScavTrap	soso;

	test_name("ScavTrap 'soso' should call Copy assignment operator constructor and his _name become 'dad'");
	soso = z;
	soso.attack("monster");

	test_name("ScavTrap 'soso' should inform beeing on [Gate keeper] mode");
	soso.guardGate();


	test_name("INHERITANCE 2");
	test_name("should display the constructor message of ClapTrap then the FragTrap one");
	FragTrap	xx("mum");

	test_name("FragTrap should be able to use the methods inherited from the base class ClapTrap with the new initialized values");
	xx.attack("bruh");
	xx.takeDamage(5);
	xx.beRepaired(5);

	test_name("Coplien");
	test_name("FragTrap 'y' should be created with Name constructor");
	FragTrap	yy("dad");

	test_name("FragTrap 'z' shoud copy 'y' by calling Copy constructor");
	FragTrap	zz = yy;
	zz.attack("villain");

	test_name("FragTrap 'tibo' should call Default constructor and his _name is 'noName'");
	FragTrap	tibo;

	test_name("FragTrap 'tibo' should call Copy assignment operator constructor and his _name become 'dad'");
	tibo = zz;

	test_name("FragTrap 'tibo' should display a positive high-fives request on the standard output");
	tibo.highFivesGuys();

	test_name("ScavTrap and FragTrap destructor messages should be called before ClapTrap destructor messages");
	std::cout << "\n";
	return (0);
}
