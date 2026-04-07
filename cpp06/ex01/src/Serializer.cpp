/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:17:35 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 18:22:21 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

uintptr_t Serializer::serialize(void* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

void* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<void*>(raw);
}