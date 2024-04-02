/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:49:28 by ixu               #+#    #+#             */
/*   Updated: 2024/02/25 15:34:32 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		ptr = (char *)malloc(sizeof(char));
		if (ptr != NULL)
			ptr[0] = '\0';
		return (ptr);
	}
	if (ft_strlen(s + start) < len)
		ptr = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && (i + start) < ft_strlen(s))
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
