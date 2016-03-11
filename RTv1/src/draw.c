#include <RTv1.h>
#include <stdio.h>

void	pixel_put_to_image(t_tool *t, int x, int y, float r, float g, float b)
{
    t->image.data = mlx_get_data_addr(t->mlx_img, &t->image.bpp, &t->image.size_line, &t->image.endian);
    t->image.data[x * t->image.bpp / 8 + y * t->image.size_line] = (unsigned char)b;
    t->image.data[x * t->image.bpp / 8 + 1 + y * t->image.size_line] = (unsigned char)g;
    t->image.data[x * t->image.bpp / 8 + 2 + y * t->image.size_line] = (unsigned char)r;
}

t_ray  get_ray(t_tool *t, float x, float y)
{
    t_ray  ray;
    
    ray.O.x = t->cam.pos.x;
    ray.O.y = t->cam.pos.y;
    ray.O.z = t->cam.pos.z;
    
    ray.D.x = t->cam.upleft.x + t->cam.r_vect.x * t->cam.x_indent * x - t->cam.h_vect.x * t->cam.y_indent * y;
    ray.D.y = t->cam.upleft.y + t->cam.r_vect.y * t->cam.x_indent * x - t->cam.h_vect.y * t->cam.y_indent * y;
    ray.D.z = t->cam.upleft.z + t->cam.r_vect.z * t->cam.x_indent * x - t->cam.h_vect.z * t->cam.y_indent * y;
    
    //printf("x_indent = %f / y_indent = %f\n", t->cam.x_indent, t->cam.y_indent);
    //sleep(1);
    //printf("x = %f / y = %f / z = %f\n",ray.D.x, ray.D.y, ray.D.z);
    vectorNorm(&ray.D);
    //printf("x = %f / y = %f / z = %f\n",ray.D.x, ray.D.y, ray.D.z);
    return (ray);
}


void    draw(t_tool *t, float x, float y)
{
    t_ray  ray;
    
    t_cyl cyl;
    t_cone cone;
    t_sphere sphere;
    t_plan  plan;
    
    float coef = 20000;
    
    float red = 0;
    float green = 100;
    float blue = 100;
    
    sphere.rad = 100;
    sphere.O.x = 0;
    sphere.O.y = 0;
    sphere.O.z = 300;
    
    cone.O.x = 0;
    cone.O.y = 0;
    cone.O.z = -100;
    cone.h = 20;
    cone.rad = 10;
    
    cyl.vect.O.x = 0;
    cyl.vect.O.y = 0;
    cyl.vect.O.z = -100;
    cyl.vect.D.x = 0;
    cyl.vect.D.y = 1;
    cyl.vect.D.z = 0;
    cyl.rad = 15;
    
    plan.a = 0;
    plan.b = 1;
    plan.c = 0;
    plan.d = 20;
    
    ray = get_ray(t, x, y);
    
    if (intersection_sphere(sphere, ray, &coef))
    {
//        // On calcul le point d'impact
//        t_pos Impact;
//        Impact.x = ray.O.x + ray.D.x * coef;
//        Impact.y = ray.O.y + ray.D.y * coef;
//        Impact.z = ray.O.z + ray.D.z * coef;
//        
//        //printf("x = %f / y = %f / z = %f\n",Impact.x, Impact.y, Impact.z);
//        //sleep(1);
//        
//        // On calcule la normale sur la sphere
//        t_pos Distance;
//        
//        Distance.x = Impact.x - sphere.O.x;
//        Distance.y = Impact.y - sphere.O.y;
//        Distance.z = Impact.z - sphere.O.z;
//        
//        vectorNorm(&Distance);
//        // la norme
//        float Norme = vectorDot(&Distance,&Distance);
//        float Temp = Norme * Norme;
//        Temp = 1 / sqrt(Temp);
//        Norme = Temp * Norme;
//        
//        
//        if (Norme != 0)
//        {
//            // On calcul la lumière ici ( Modèle de lambert )
//            
//            
//            // Distance entre la lumière et l'impact
//            t_pos RayLightDist;
//            RayLightDist.x = 0 - Impact.x;
//            RayLightDist.y = 0 - Impact.y;
//            RayLightDist.z = 0 - Impact.z;
//            
//            // Produit scalaire
//            float NormeRayDist = vectorDot(&RayLightDist,&RayLightDist);
//            
//            t_pos RayLightDir;
//            
//            // la norme
//            if (NormeRayDist != 0)
//            {
//                RayLightDir.x = RayLightDist.x / Norme;
//                RayLightDir.y = RayLightDist.y / Norme;
//                RayLightDir.z = RayLightDist.z / Norme;
//            }
//            
//            t_pos IntensityLight;
//            IntensityLight = vectorMul(&RayLightDir,&Distance);
//            
//            float lambert = (IntensityLight.x * Norme)+ (IntensityLight.y * Norme)+(IntensityLight.z * Norme);
//            
//            red = (120  * lambert);
//            green = 60 + (100 * lambert);
//            blue  = 60 + (100  * lambert);
//        
//            if (red < 0)
//                red = 0;
//            if (blue < 0)
//                blue = 0;
//            if (green < 0)
//                green = 0;
//            if (red > 255)
//                red = 255;
//            if (blue > 255)
//                blue = 255;
//            if (green > 255)
//                green = 255;
//            
            //printf("%f / %f / %f\n", inter.x, inter.y, inter.z);
            pixel_put_to_image(t, x, y, red, green, blue);
        
    }
}

