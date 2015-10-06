###Homebrew cheatsheet

- If **--dry-run** or **-n** is passed, Homebrew will list all files which would be linked or which would be deleted by brew link --overwrite, but will not actually  link  or  delete any files.
- Global commands
```sh
# Update brew
$ brew update
# List installed
$ brew list
# What’s due for upgrades?
$ brew outdated
```
- Install a package
<br>`$ brew install boost`
- Upgrade a package
<br>`$ brew upgrade boost`
- Unlink
<br>`$ brew unlink boost`
- Link
<br>`$ brew link boost`
- Change versions
<br>`$ brew switch boost 1.56.0`
- See what versions you have
<br>`$ brew list --versions boost`
- List versions, caveats, etc
<br>`$ brew info git`
- Remove old versions
<br>`$ brew cleanup boost`
- Edit this formula
<br>`$ brew edit boost`
- Open homepage
<br>`$ brew home boost`
- To see where all of the files are located, use the list [formula] --verbose
<br>`brew list boost --verbose`
