echo 'Working directory' #/sogang/under/cse20131251/shell
read dirname #directory �̸��� �Է��� ����

if [ -n "$dirname" ]
then
        if [ -d "$dirname" ]
        then
                cd "$dirname"
        else
                echo "Error : Directory does not exist"
                exit 0
        fi
fi
 
for dir in *
do 
newname=`echo $dir | tr "[a-z] [A-Z]" "[A-Z] [a-z]"` #���� newname�� dir��      ��ҹ��ڸ�tr�� �̿��ؼ� �ٲ۰�
mv $dir $newname #$dir�� newname���� �ٲ۴�.
done
