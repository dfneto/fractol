# Fractol
https://harm-smits.github.io/42docs/libs/minilibx/hooks.html
<br/>
https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-introduction/videos/introduction-to-minilibx




Para funcionar vc deve ter o libmlx.a dentro de deps/mlx que vc gera ao rodar make



# Mandelbrot
make && ./fractol 1

# Julia
make && ./fractol 2

make && ./fractol 2 -1.17918 -0.02032

2 means julia fractal

The others 2 numbers you can vary. Take examples at https://complex-analysis.com/contenido/conjunto_de_julia.html


# TODO:
Muar o rango para -2 a 2 no caso de Julia

Zoom no ponteiro do mouse

Melhorar o makefile e entender melhor o .d, -MMD e -include $(DEPS)