#!/usr/bin/python
from Tkinter import *
import tkMessageBox
import array as arr

flame_data = {'F': 'Friends', 'L': 'Love', 'A': 'Affection', 'M': 'Marriage', 'E': 'Enemey', 'S': 'Sister', }
def popupmsg(msg):
    tkMessageBox.showinfo("Information",msg)

def flames(n):
    out = ['F', 'L', 'A', 'M', 'E', 'S']
    it=6
    while it > 1 :
        mod=n%it
        del out[mod]
        it = it - 1
    #print "Value %s" % (flame_data[out[0]])
    popupmsg (flame_data[out[0]])

def show_entry_fields():
    #print("Start Flames")
    value = 0
    PersonX = e1.get().replace(" ", "").lower()
    PersonY = e2.get().replace(" ", "").lower()
    for letter in PersonX:
        result=PersonY.find(letter)
        #print("Result is " , result)
        if result < 0:
            value = value + 1
    for letter in PersonY:
        result=PersonX.find(letter)
        #print("Result is " , result)
        if result < 0:
            value = value + 1
    #print("Value is ", value)
    flames(value)

root = Tk()
root.title("Flames")


text2 = Text(root, height=4, width=100)
#scroll = Scrollbar(root, command=text2.yview)
#text2.configure(yscrollcommand=scroll.set)
#text2.tag_configure('bold_italics', font=('Arial', 12, 'bold', 'italic'))
#text2.tag_configure('big', font=('Verdana', 20, 'bold'))
#text2.tag_configure('color', foreground='#476042', font=('Tempus Sans ITC', 12, 'bold'))
text2.insert(END,'Test Program for python graphics\n', 'big')
quote = """
Enter your name and your friend name click ok 
To play flames
"""
text2.insert(END, quote, 'color')
#text2.insert(END, 'follow-up\n', 'follow')
text2.grid(row=0, column=1)
#scroll.pack(side=RIGHT, fill=Y)
label1 = Label(root, text="Your Name").grid(row=1, column=0)
Label(root, text="Friend\'s Name").grid(row=2, column=0)

e1 = Entry(root)
e2 = Entry(root)

e1.grid(row=1, column=1)
e2.grid(row=2, column=1)

Button(root, text='Quit', command=root.quit).grid(row=3, column=0)
Button(root, text='Flames', command=show_entry_fields).grid(row=3, column=1)
#scroll.pack(side=RIGHT, fill=Y)
root.mainloop()
