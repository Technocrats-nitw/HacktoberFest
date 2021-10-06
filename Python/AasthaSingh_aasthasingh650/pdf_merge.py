"""
Author-Aastha Singh
pythonscript to merge all pdf files in one single pdf present in the current working directory
"""

import os
from PyPDF2 import PdfFileMerger            #pip install PyPDF2

#listing out all the pdf in the current working directory using OS library
pdfs = [file for file in os.listdir() if file.endswith(".pdf")]

merger = PdfFileMerger()

#merging all the pdf
for pdf in pdfs:
    merger.append(open(pdf, 'rb'))

with open("merged-result.pdf", "wb") as merge:
    merger.write(merge)