#include <SDL_image.h>
/*#include "ContentManager.h"


app::ContentManager::ContentManager(SDL_Renderer* render)
{
	this->renderer = render;
}


app::ContentManager::~ContentManager()
{
}


SDL_Texture* app::ContentManager::loadTexture(const char* file)
{
	std::map<char*, SDL_Texture*>::iterator iter = images.find( (char*)file );

	// Does this element already exist in the map?
	if (iter == images.end())
	{
		// It doesn't already exist. Add it and return
		return (images[(char*)file] = IMG_LoadTexture(renderer,file));
	}
	// It does exist, just return the value from the iterator!
	return iter->second;
}

bool app::ContentManager::unloadTexture(const char* file)
{
	std::map<char*, SDL_Texture*>::iterator iter = images.find((char*)file);
	if (iter == images.end())
		return false;

	SDL_DestroyTexture(iter->second);
	iter->second = NULL;
	images.erase(iter);
	return true;
}
bool app::ContentManager::unloadTexture(SDL_Texture* tex)
{
	for (std::map<char*, SDL_Texture*>::iterator iter = images.begin(); iter != images.end(); ++iter)
	{
		if (iter->second == tex)
		{
			SDL_DestroyTexture(iter->second);
			iter->second = NULL;
			images.erase(iter);
			return true;
		}
	}
	return false;
}

bool app::ContentManager::unloadAll()
{
	while (images.end() != images.begin())
		this->unloadTexture(images.begin()->first);
	return true;
}
*/