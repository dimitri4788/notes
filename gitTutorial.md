## Git stuff

- Git is a distributed version control and source code management system.
- It does this through a series of snapshots of your project, and it works with those snapshots to provide you with functionality to version and manage your source code.
- A git repository is comprised of the .git directory & working tree.
    - The .git directory contains all the configurations, logs, branches, HEAD, and more.
    - Working tree is basically the directories and files in your repository. It is often referred to as your working directory.
- Index
    - The Index is the staging area in git.
    - It’s basically a layer that separates your working tree from the Git repository. This gives developers more power over what gets sent to the Git repository.
- Commit
    - A git commit is a snapshot of a set of changes, or manipulations to your Working Tree.
    - For example, if you added 5 files, and removed 2 others, these changes will be contained in a commit (or snapshot). This commit can then be pushed to other repositories, or not!
- Branch
    - A branch is essentially a pointer that points to the last commit you made. As you commit, this pointer will automatically update and point to the latest commit.
- HEAD and head
    - HEAD is a pointer that points to the current branch. A repository only has 1 active HEAD.
    - head is a pointer that points to any commit. A repository can have any number of heads.
- Stages of Git
    - Modified
    - Staged
    - Committed


**Commands**
 init
```sh

```












### Sources
- http://learnxinyminutes.com/docs/git/
