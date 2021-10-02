import os
from fnmatch import fnmatch


def delete_all_with_extension(pattern):
    root = '.'
    for path, subdirs, files in os.walk(root):
        for name in files:
            if name.endswith(pattern):
                print(os.path.join(path, name))
                os.remove(os.path.join(path, name))
if __name__ == '__main__':
    pattern = 'abcd'
    delete_all_with_extension(pattern)
    
