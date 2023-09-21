#Fractol

https://harm-smits.github.io/42docs/libs/minilibx/hooks.html


<br/>
https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-introduction/videos/introduction-to-minilibx


<br/>
Para funcionar vc deve ter o libmlx.a dentro de deps/mlx que vc gera ao rodar make



Draw pixels on an image
💡 Don’t use mlx_pixel_put like I did at first.

It’s slow and you can’t re-render the canvas.

Use mlx_put_image_to_window instead.