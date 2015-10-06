###Homebrew cheatsheet

- If --dry-run or -n is passed, Homebrew will list all files which would be linked or which would be deleted by brew link --overwrite, but will not actually  link  or  delete any files.
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
`$ brew install boost`
- Upgrade a package
`$ brew upgrade boost`
- Unlink
`$ brew unlink boost`
- Link
`$ brew link boost`
- Change versions
`$ brew switch boost 1.56.0`
- See what versions you have
`$ brew list --versions boost`
- List versions, caveats, etc
`$ brew info git`
- Remove old versions
`$ brew cleanup boost`
- Edit this formula
`$ brew edit boost`
- Open homepage
`$ brew home boost`
- To see where all of the files are located, use the list [formula] --verbose
`brew list boost --verbose`
