mogrify -resize 50% -format gif *.png
gifsicle --delay=10 --loop *.gif > anim.gif 