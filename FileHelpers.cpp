#include "FileHelpers.h"


std::string oSDL::GetExtension(std::string& path)
{
	// Look for the last '.', and everything after is considered the extension
	size_t pos = path.find_last_of('.');

	return path.substr(pos);
}
std::string oSDL::GetFilename(std::string& path)
{
	// Look for the last slash of the filepath
	size_t pos = path.find_last_of('/');
	if (pos == std::string::npos)
		pos = path.find_last_of('\\');
	if (pos == std::string::npos)
		pos = 0;

	size_t end = path.find_last_of('.');
	if (end == std::string::npos || end <= pos)
		end = path.length();

	return path.substr(pos, (end - pos));
}
std::string oSDL::GetDirectory(std::string& path)
{
	size_t pos = path.find_last_of('/');
	if (pos == std::string::npos)
		pos = path.find_last_of('\\');
	if (pos == std::string::npos)
		pos = 0;

	return path.substr(0,pos);
}