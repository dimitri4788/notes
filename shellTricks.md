Some cool tricks in Shell
=========================

This file contains some useful tricks in Shell.

<br>

```sh
#Change names of files:
$ for i in `ls`; do Old=$i; New=`echo $i | sed 's/036\.mp4/036\.3gp/'`; echo $Old $New; done
$ for i in `cat temp.txt`; do Old=$i; New=  echo sed -i '' "s/insertMachine_/_insertMachine/g” <fileName>; done

#Grab first 13 bytes from an flv file and then cat with the flv file to be able to play in VLC:

$ dd if=file.flv of=header.bin bs=13 count=1
$ cat header.bin fragment.flv > video.flv

$ cat inputTSV.tsv | awk '{print $5,"\t",$4,"\t"}' | sort -k 1,1


#Merging DASH chunks for a file:
$ ls -l | sort -k 9 | grep BabyLaughingHD1_8mwE2N59H5g_itag-134 | awk '{print $9}' | sort -t "." -n -k 3,3 > temp.txt ; ./mergeChunks.sh ; mv output.mp4 ~/xxx.mp4

#Give the sorted last column (file names):
$ ls -l | sort -k 9 | awk '{print $9}’

#Get the number of characters and the unique files;
$ for i in `ls | sed 's/_/ /g' | awk '{print $4}' | sort | uniq`; do CHARS=`echo $i | wc -m`; NAME=`echo $i`; echo $CHARS $NAME; done | sort -nk 1 | less

#LD_LIBRARY_PATH:
$ LD_LIBRARY_PATH=$FUSION_LIBRARY_PATH mdutil

#Do not export LD_LIBRARY_PATH
#Set it for a specific <command_line>. For example, in above case we are setting it for “mdutil”. Other command_line tools would not look for this LD_LIBRARY_PATH.


#Split a string on underscore, example file names:
$ ls -l | sort -k 9 | awk '{print $9}' | sed s/_/\\t/g | cut -f 3

#rsync
$ rsync -av deepanshua.old/ deepanshu/

#http://www.tecmint.com/rsync-local-remote-file-synchronization-commands/

$ rsync -ave ssh --rsync-path=/usr/local/bin/rsync /scr/jtidemann/videos/tmp/ jtidemann@10.198.20.22:/vc/results/jtidemann/testing/qao-dev/



#To remove spaces from file names (replace with underscore or fill it):
$ for i in *' '*; do old="$i"; new=`echo $i | sed 's/ /_/g'`; echo mv "$old" $new; done
$ for i in *' '*; do old="$i"; new=`echo $i | sed 's/ /_/g'`; mv "$old" $new; done
$ for i in *' '*; do old="$i"; new=`echo $i | sed 's/ //g'`; mv "$old" $new; done

#Create and extract a tar.gz archive using command line tar zip
#http://www.zyxware.com/articles/2009/02/26/how-to-create-and-extract-a-tar-gz-archive-using-command-line
#To create a tar.gz archive from a given folder you can use the following command:
$ tar -zcvf tar-archive-name.tar.gz source-folder-name
#This will compress the contents of source-folder-name to a tar.gz archive named tar-archive-name.tar.gz

#To extract a tar.gz compressed archive you can use the following command:
$ tar -zxvf tar-archive-name.tar.gz


#Split string with delimiter colon (:)
$ for i in $(echo $PATH |  tr ":" "\n"); do echo $i; done

#Use sed to change a variable name in a file
$ sed -i '' "s/insertMachine_/_insertMachine/g” <fileName>
$ sed -i '' "s/insertMachine_/_insertMachine/g” * // In all files in the CWD


#Get the symbols from the object file
$ nm -gU /usr/lib/libsqlite3.dylib



#To find strings in a object, or other binary file
$ strings -a /usr/local/Cellar/sqlite/3.8.8.3/lib/libsqlite3.dylib

#Command to find how many lines of code I have written
$ find . -type f \( -name "*.cpp" -o -name "*.hpp" \) | grep -v "server_https\|server_http\|https_examples\|build" | xargs wc -l
$ find . -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*ts.txt" \) | grep -v "server_https\|server_http\|https_examples\|build" | xargs wc -l


#Option-click: Move cursor to location clicked


#How to I find and replace every occurrence of: subdomainA with subdomainB
# in every text file under the /home/www/ directory tree (recursive find/replace).

$ find . -type f -print0 | xargs -0 sed -i '' -e 's/subdomainA/subdomainB/g'

#Replace all LOG( with //LOG(
$ find . -type f -print0 | xargs -0 sed -i '' -e 's/LOG(/\/\/LOG(/g’

#Find how many threads were used in a log file
$ cat sample_0.log  | awk '{print $3}' | sort | uniq
```
