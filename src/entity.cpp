#include "entity.hpp"

Entity::Entity(SDL_Renderer *global_renderer, std::string image_path, int p_x, int p_y, int p_w, int p_h)
    : renderer_(global_renderer), x_(p_x), y_(p_y), w_(p_w), h_(p_h)
{
    texture_ = IMG_LoadTexture(renderer_, image_path.c_str());

    if (texture_ == NULL)
    {
        std::cerr << "Warning : some texture died\n";
    }
    on_window_ = {int(x_), int(y_), int(w_), int(h_)};
}

void Entity::display()
{
    SDL_RenderCopy(renderer_, texture_, NULL, &on_window_);
}

Entity::~Entity()
{
    SDL_DestroyTexture(texture_);
}