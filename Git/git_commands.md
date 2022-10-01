## GIT COMMANDS

### Creating New Repository
```git init``` command is used to create new repository
```
$ git init
```
It can be used to convert an existing, unversioned project to a Git repository or initialize a new, empty repository.

<hr>

### Adding the Location of your Remote Repository
```git remote add origin <remote url>``` command will create 'origin' if it doesn't exists.
```
$ git remote add origin https://github.com/user/repo.git
```
This command is the second step in the command series after using git init. It means you are adding the location of your remote repository where you wish to push/pull your files to/from."
Your remote repository could be anywhere on github, gitlab, etc.
Origin is used to avoid to type the entire path for remote every time and henceforth you are declaring that you will use this name(origin) to refer to your remote.

<hr>

### Adding Files in the Repository
```git add``` command adds new or changed files in your working directory to the Git staging area.
```
$ git add README.md
```
This command will select the README.md file, and move it to the staging area, marking it for inclusion in the next commit. 

<hr>

### Switching between Different Versions
```git checkout``` command is used for the act of switching between different versions of a target entity.
```
$ git checkout <branchname> 
```
The git checkout command operates upon three different entities which are files, commits, and branches. It checks the branches and updates the files in 
the working directory to match the version already available in that branch, and it forwards the updates to Git to save all new commit in that branch.

Adding `-b` flag after checkout creates a new branch if not existing already.

<hr>

### Recording the Changes in the Repository 
```git commit ``` command captures a snapshot of the project's currently staged changes
```
$ git commit
```
A commit command is used to fetch updates from the staging area to the repository.

<hr>

### Uploading all local branch commits
```git push``` command uploads all local branch commits to the corresponding remote branch.
```
$ git push <remote> <branch-name>
```
This command updates the remote branch with local commits. Pushing changes to the remote makes your commits accessible to others who you may be collaborating with. 
This will also update any open pull requests with the branch that you're working on.

<hr>

### Update the local version of a Repository
```git pull``` command is used to fetch and download content from a remote repository and immediately update the local repository to match that content.
```
$ git pull <remote> <branch-name>
```
This command will fetch the specified remote’s copy of the current branch and immediately merge it into the local copy.

<hr>

### Display the State
```git status``` command is used to display the state of the repository and staging area. It allows us to see the tracked, untracked files and changes.
```
$ git status 
```
This command will command only output information, it won't modify commits or changes in your local repository.

### Compare with previous commit
```git diff``` command is used to basically display the difference between last committed code and current code.
```
$ git diff 
```
This command will command only output information, it won't modify commits or changes in your local repository.

<hr>

### Saves the Uncommitted Changes Locally
```git stash``` command enables you to switch branches without committing the current branch.
```
$ git stash 
```
This command temporarily shelves (or stashes) changes you've made to your working copy so you can work on something else, and then come back and re-apply them later on.

<hr>

```py
  Author = "Aastha Singh"
  if pull_request.like == True:
    follow (Author)
```
