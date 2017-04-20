# ifndef PLANE_HPP
# define PLANE_HPP

#include "Object.hpp"
#include "Weapon.hpp"

class Plane : public Object {

  public:
    Plane(void);
    ~Plane(void);
    Plane(const Plane & src);
    Plane & operator = (const Plane & src);

    Weapon *dropWeapon(int offset);
    void moveLeft(void);
    void moveRight(void);
    void moveUp(void);
    void moveDown(void);
};

#endif
