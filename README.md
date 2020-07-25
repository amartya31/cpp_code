# cpp_code
$ git config --global user.name "amartya31"
$ git config --global user.email ghosh.amartya31@gmail.com

#to set up remote and repetative logins 

#TO generate host ket

Generating an SSH key pair
The first step in using SSH authorization with GitHub is to generate your own key pair.

You might already have an SSH key pair on your machine. You can check to see if one exists by moving to your .ssh directory and listing the contents.

$ cd ~/.ssh
$ ls
If you see id_rsa.pub, you already have a key pair and don't need to create a new one.

If you don't see id_rsa.pub, use the following command to generate a new key pair. Make sure to replace your@email.com with your own email address.

$ ssh-keygen -o -t rsa -C "your@email.com"
(The -o option was added in 2014; if this command fails for you, just remove the -o and try again)

When asked where to save the new key, hit enter to accept the default location.

Generating public/private rsa key pair.
Enter file in which to save the key (/Users/username/.ssh/id_rsa):
You will then be asked to provide an optional passphrase. This can be used to make your key even more secure, but for this lesson you can skip it by hitting enter twice.

Enter passphrase (empty for no passphrase):
Enter same passphrase again:

$ cat ~/.ssh/id_rsa.pub
The output should look something like this:

GO to user setting, then set public key

#TO avoide repetative login

git remote -v
#git remote set-url git@github.com:USERNAME/REPOSITORY.git
git remote set-url origin git@github.com:amartya31/cpp_code.git
