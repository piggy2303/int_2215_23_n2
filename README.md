# step 1

    git init

add all your file to git

    git add .

commit and push

    git commit -m "your comment"

    git push origin master

if git push get error authentication
you need to go github.com
login => profile => setting =>scorll => developer settings
=> token => generate new token => expired 3-6 months
=> have token => SAVE IT SAVE IT SAVE IT

    git remote set-url origin https://TOKEN@github.com/USERNAME/REPO.git

if more error but not authentication error => google

# install sdl

    brew install SDL2

    brew install SDL2_image

    brew install SDL2_ttf

# running SDL

    g++ index_sdl.cpp -o hello_sdl2 -lSDL2
    ./hello_sdl2

# if get error not found SDL2

go this `https://www.libsdl.org/download-2.0.php`

dowload file `SDL2-2.0.20.dmg`

open it and copy folder SDL2.framework to `/Library/Frameworks/`

run it : `./start.sh` again
