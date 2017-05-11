# homegit
In home, do coding !
#
#
#   统计文件的字符数、单词数以及总行数，包括：
#
#   每行的字符数和单词数
#   文件的总字符数、总单词数以及总行数
#
#   注意：
#   空白字符（空格和tab缩进）不计入字符总数；//注意标准的Linux的wc命令是将空格，制表符都算作一个字符，并且一行结束字符要加一个结束符(
#	是不是'\n'呢，需要写代码测试
#	)
#   单词以空格为分隔；
#   不考虑一个单词在两行的情况；
#   限制每行的字符数不能超过1000。
#   请先看代码：
#------------------------------------------------
#   在创建文件demo.txt，并输入如下的内容：
#
#   I am Chinese. I love my country.
#   China has 960 square kilometers of territory.
#   China has a population of 1.35 billion.
#   The capital of China is Beijing.
#
#   目前不需要做到，解析多个文件，以及文件内容包含特殊字符，只需要以空格，逗点，句点，叹号为分割的单词既可以。
#
#	./a.out file1
#   运行程序，输出结果为：
#
#	Input file name: d://demo.txt
#	line   words  chars
#	1      7      26
#	2      7      39
#	3      7      33
#	4      6      27
#	5      0      0
#	6      2      7
#	7      0      0
#	8      1      10
#	Total: 8 lines, 30 words, 142 chars
