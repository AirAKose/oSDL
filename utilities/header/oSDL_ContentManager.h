#ifndef _MY_oSDL_CONTENT_MANAGER_HEADER_
#define _MY_oSDL_CONTENT_MANAGER_HEADER_

/*#include <list>
#include <map>
#include <SDL.h>
#include <string>
#include "oSDL_Renderer2D.h"
#include "oSDL_Texture.h"

namespace oSDL
{
	class ContentManager
	{
		SDL_Renderer* _renderer;
		std::map<std::string, oSDL::Texture*> _images;

	public:
		ContentManager(SDL_Renderer* render);
		ContentManager(oSDL::Renderer2D* render);
		~ContentManager();

		oSDL::Texture* LoadTexture(std::string file);
		oSDL::Texture* AddTexture(std::string resourceName,SDL_Texture* tex);
		oSDL::Texture* GetTexture(std::string file);

		bool UnloadTexture(std::string file);
		bool UnloadTexture(oSDL::Texture* tex);
		bool UnloadTexture(SDL_Texture* tex);

		bool UnloadAll();
		void Destroy();
	};
}*/

#endif