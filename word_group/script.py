# Adds Words To Database With Given Concept
# Takes words fom in.csv and prompts out.csv
import pyodbc

conn = pyodbc.connect('Driver={SQL Server};'
                      'Server=DESKTOP-R6BFD5E\MSSQLSERVER01;'
                      'Database=KelimeDB;'
                      'Trusted_Connection=yes;')

def is_word_concept_exist(word, concept):
    cursor = conn.cursor()
    query = "SELECT TOP 1 [WordID] FROM [dbo].[WordConcept] where WordID = ? AND ConceptID = ? "
    cursor.execute(query, word, concept)
    if cursor.fetchone():
        return True
    else:
        return False

def is_word_exist(word):
    cursor = conn.cursor()
    query = "SELECT TOP 1 [ID] FROM [dbo].[Word] where ID = ?"
    cursor.execute(query, word)
    if cursor.fetchone():
        return True
    else:
        return False

def is_concept_exist(concept):
    cursor = conn.cursor()
    query = "SELECT TOP 1 [ID] FROM [dbo].[Concept] where ID = ?"
    cursor.execute(query, concept)
    if cursor.fetchone():
        return True
    else:
        return False

def add_word(word):
    query = "INSERT INTO [dbo].[Word]([ID],[Count]) VALUES (?,?)"
    cursor = conn.cursor()
    cursor.execute(query, word, 0)

def add_concept(concept):
    query = "INSERT INTO [dbo].[Word]([ID]) VALUES (?)"
    cursor = conn.cursor()
    cursor.execute(query, concept)


def word_concept_occurence(word, concept):
    query = "UPDATE [dbo].[WordConcept] SET [Count] = [Count] + 1 WHERE [WordID] = ? AND [ConceptID] = ?"
    cursor = conn.cursor()
    cursor.execute(query, word, concept)
    return True

def word_occurence(word):
    query = "UPDATE [dbo].[Word] SET [Count] = [Count] + 1  WHERE [ID] = ?"
    cursor = conn.cursor()
    cursor.execute(query, word)
    return True

def add_word_concept(word, concept, concept_order):
    query = "INSERT INTO [dbo].[WordConcept] ([WordID], [ConceptID],[ConceptOrder]) VALUES (?,?,?)"
    cursor = conn.cursor()
    cursor.execute(query, word, concept, concept_order)
    return True

def insert(word, concept):
    if is_word_exist(word):
        word_occurence(word)
        if is_concept_exist(concept):
            if is_word_concept_exist(word, concept):
                word_concept_occurence(word, concept)
                save_line(" - Duplicate Word: " + word + " : " + concept)
            else:
                add_word_concept(word, concept, 1)
                save_line("[ + ] - Concept Added: " + word + " : " + concept)
        else:
            add_concept(concept)
            save_line("[ + ] - Concept Added: " + concept)
            insert(word, concept)
    else:
        add_word(word)
        save_line("[ + ] - Word Added: " + word)
        insert(word, concept)

def read_lines(concept, inputfilename):
    with open(inputfilename) as infile:
        for line in infile:
            insert(line.rstrip(), concept)

def save_line(line):
    with open('out.csv', 'a') as the_file:
        the_file.write(line + "\n")



# add_concept("Fly Me to the Moon Test")
read_lines("Fly Me to the Moon Test","in.csv")
conn.commit()
