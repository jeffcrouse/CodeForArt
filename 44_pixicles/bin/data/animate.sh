mogrify -resize 50% -format gif capture/*.png
gifsicle --delay=10 --loop capture/*.gif > anim.gif 