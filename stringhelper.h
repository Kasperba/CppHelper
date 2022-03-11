//
// Copyright 2022 Kasper Blok Andersen
//
// Use of this Header-file is governed by the Apache License, Version 2.0
//

#ifndef __STRING_HELPER_H__
#define __STRING_HELPER_H__

#include <vector>
#include <string>

namespace std
{
	namespace helpers
	{
		std::vector<std::string*>* split(const std::string& src, const std::string& search, bool removeEmpty)
		{
			std::vector<std::string*>* result = new std::vector<std::string*>();

			std::size_t pos = 0, new_pos = 0;

			while (TRUE)
			{
				new_pos = src.find(search, pos);

				if (new_pos == std::string::npos)
				{
					std::size_t non_match_len = src.size() - pos;

					if (non_match_len > 0)
					{
						std::string* non_match = new std::string(src.substr(pos, non_match_len));
						result->push_back(non_match);
					}
					else if (removeEmpty == FALSE)
					{
						new_pos = pos + search.length();

						if (new_pos == src.length())
						{
							result->push_back(new std::string(""));
						}
					}

					break;
				}

				std::size_t non_match_len = new_pos - pos;

				if (non_match_len > 0)
				{
					std::string non_match = src.substr(pos, non_match_len);
					result->push_back(new std::string(non_match));
				}
				else if (removeEmpty == FALSE)
				{
					result->push_back(new std::string(""));
				}

				pos = new_pos + search.size();
			}


			return result;
		}

		std::string* replace(const std::string& src, const std::string& search, const std::string replace)
		{
			std::string* result = new std::string();

			std::size_t pos = 0, new_pos = 0;

			while (TRUE)
			{
				new_pos = src.find(search, pos);

				if (new_pos == std::string::npos)
				{
					std::size_t non_match_len = src.size() - pos;

					if (non_match_len > 0)
					{
						std::string non_match = src.substr(pos, non_match_len);
						result->append(non_match);
					}

					break;
				}

				std::size_t non_match_len = new_pos - pos;

				if (non_match_len > 0)
				{
					std::string non_match = src.substr(pos, non_match_len);
					result->append(non_match);
				}

				result->append(replace);

				pos = new_pos + search.size();
			}

			return result;
		}
	}
}

#endif