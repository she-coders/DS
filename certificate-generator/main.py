''' 
authored by palak thapar 
'''

import os
names = []
input_file = 'input.txt'
try:

    if os.stat(input_file).st_size == 0:  # check for an empty file
        print('Sorry, the file {input_file} is empty'.format(input_file=input_file))
    else:
        for line in open(input_file, 'r'):
            for name in line.strip().split(','):
                names.append(name)
except FileNotFoundError: # check for a non-existing file
    msg = 'Sorry, the file {input_file} does not exist.'.format(input_file=input_file)
    print(msg)

for name in names: 
    with open(name + '.txt', 'w') as wp:
        print("generating certificate for {name}".format(name=name))
        content = \
            '''
  ----------------------------------------------------------------------------
  |                    Certificate of Completion                             |
  |                                                                          |
  |                                                                          |
  | This is to certify that {name} has successfully completed the          |
  |              course in Micro Biology.                                    |
  |                                                                          |
  |                                                                          |
  |                                                                          |
  |                                                                          |
  | ______________________                              _______________      |
  | Signature of Instructor                             Signature of HOD     |
  |                                                                          |
  |                                                                          |
  |                                                                          |
  |                                                                          |
  |                                                                          |
   --------------------------------------------------------------------------- 
   '''
        wp.write(content.format(name=name)) # writing the content to each file
        wp.close() # closing the file 
    
    # a check for success
    print("successfully generated certificate for {name}".format(name=name))
    print()
