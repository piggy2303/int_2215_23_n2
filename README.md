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
