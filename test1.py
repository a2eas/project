import tkinter as tk
from tkinter import ttk
from tkinter.filedialog import askopenfilename
from tkinter.ttk import Style
class app(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('automation project')
        self.columnconfigure(0,weight=1)
        self.rowconfigure(0,weight=1)    
class frmae(ttk.Frame):
    def __init__(self,parent):
        super().__init__(parent)
        self.style = Style()
        self.style= self.style.configure('My.TFrame',background = 'Gray')
        self.grid(column=0,row=0,sticky='ew')
        self.columnconfigure(0,weight=1)
        self.rowconfigure(0,weight=1)
        self.entry = ttk.Entry()
        self.entry.grid(column=0,row=0)
        self.entry.bind('<Return>',func=self.command)
        self.text_List = tk.Listbox()
        self.text_List.grid(column=0,row=1)
        self.index_setter = 0
        self.list = []
        self.config(padding=10,style="My.TFrame")
        self.save_btn = ttk.Button(command=self.save_text,text='Save')
        self.save_btn.grid(column=1,row=0)
        self.load_btn = ttk.Button(command=self.load_text,text='Load')
        self.load_btn.grid(column=1,row=1)
        self.mainloop()
    def sort_list(self,list):
        new_list = sorted(list, key=str.lower,reverse=True)
        self.text_List.delete(0,tk.END)
        return new_list
    def command(self,event=None):
        self.text = self.entry.get()
        self.list.append(self.text)
        self.new_list = self.sort_list(self.list)
        self.index_setter = len(self.new_list) + 1 
        print(self.new_list)
        for item in self.new_list:
            self.index_setter -= 1
            self.var = str(self.index_setter) + ' - ' + item
            self.text_List.insert(0,self.var)
            self.entry.delete(0,tk.END)
    def save_text(self):
        self.file_path = 'save1'
        with open(self.file_path , 'w') as file:
            for item in self.new_list:
                file.write(item + '\n')
    def load_text(self):
        self.filename = askopenfilename()
        self.filename = str(self.filename)
        with open(self.filename , 'r') as file:
            for item in file:
                self.list.append(item)
            self.list.remove(self.list[-1])
            self.command(self.list)
            

if __name__ == '__main__':
    appe = app()
    frame = frmae(appe)
