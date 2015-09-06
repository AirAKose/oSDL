#oSDL
##Objective SDL

SDL (Simple DirectMedia Layer) is a cross-platform C-language framework started by Sam Lantinga that provides access to window handling and management, event polling, basic 2d graphics, and audio. It is a beautiful framework that works, works well, and follows sensible naming conventions.

oSDL is my own C++ wrapper around the SDL framework so that it melds better with other C++ code. I am also adding a few convenience functions to make developing with the library easier, especially for beginner programmers.

For the most part, wherever the C framework has SDL, it is replaced with the namespace oSDL. Objects and their various functions in C such as SDL_Texture and SDL_SetTextureBlendMode() are reformatted into class structures in the oSDL namespace, such as oSDL::Texture and oSDL::Texture.SetBlendMode().