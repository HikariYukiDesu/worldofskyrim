#include "pluginUtils.h"


//This function may do errors, be careful
void stringHelper::split(const std::string & s, std::string delim, std::vector<std::string>& elems)
{
	std::stringstream ss;
	ss.str(s);
	std::string item;
	/*while (std::getline(ss, item, delim[0]) && std::getline(ss, item, delim[1])) {
	elems.push_back(item);
	}*/

	bool isDelimeter = false;
	while (!isDelimeter)
	{
		for (size_t i = 0; i < delim.size(); i++)
		{
			if (std::getline(ss, item, delim[i]))
			{
				break;
			}
			else
			{
				isDelimeter = true;
			}
		}

		elems.push_back(item);
	}
}

std::vector<std::string> stringHelper::split(const std::string & s, char delim[])
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

void stringHelper::easysplit(const std::string & s, char delim, std::vector<std::string>& elems)
{
	std::stringstream ss;
	ss.str(s);
	std::string item;

	while (std::getline(ss, item, delim)) {
	elems.push_back(item);
	}
}

std::vector<std::string> stringHelper::easysplit(const std::string & s, char delim)
{
	std::vector<std::string> elems;
	easysplit(s, delim, elems);
	return elems;
}