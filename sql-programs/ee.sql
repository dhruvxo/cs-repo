def update book from xml(xml file):
xml_tree = ET.parse(xml_file)
xml_root = xml_tree.getroot()
for table in xml_root:
table name = table.tag
for row in table:
data = {}
for attr in row:
data[attr.tag] = attr.text

# Construct an SQL UPDATE query
update _query = "UPDATE {table name} SET Title = %s, Author = %s, Price = %s, Quantity = %s WHERE BookID = %s"
values = [data["Title"], data["Author"], data["Price"], data["Quantity"], data["BookID"]]

# Execute the UPDATE query
cursor.execute(update_query, values)
connection.commit()

det get books from database():
cursor = connection.cursor(dictionary=True)
cursor.execute("SELECT * FROM books")
books = cursor.fetchall()
cursor.close()
return books

def get users_from_database():
cursor = connection.cursor(dictionary=T
cursor.execute("SELECT * FROM users")
users = cursor.fetchall()
cursor.close()
return users

def get carts_from database():
cursor = connection.cursor(dictionary=True)
cursor.execute("SELECT * FROM carts")
carts = cursor.fetchall()
cursor.close()
return carts

def delete book from cart(cart id):
delete query = "DELETE FROM carts WHERE CartID = %s"
cursor.execute(delete query, (cart _id,))
connection.commit()

st.title("Online Bookstore Management")

entities = ["Insert XML data","view All Tables","Delete","Update"]
selected entity = st.selectbox("Select an Option",entities)

def display entity(selected entity):

if selected entity == "View All Tables":
st.subheader( "Books ")
books = get books from_database()
st.table(books)
st.subheader(‘Users")
users = get users_from database()
st.table(users)
st.subheader( carts")
carts = get_carts_from_database()
st.table(carts)

elif selected entity == "Insert XML data":

uploaded file = st.file uploader(“Upload an XML file to insert data to the database", type=["xml"])
if uploaded file:
insert_xml_data(uploaded file)
st.success("Data inserted successfully!")
elif selected entity == "Update":

def update book from xml(xml file):
xml_tree = ET.parse(xml_file)
xml_root = xml_tree.getroot()
for table in xml_root:
table name = table.tag
for row in table:
data = {}
for attr in row:
data[attr.tag] = attr.text

# Construct an SQL UPDATE query
update _query = "UPDATE {table name} SET Title = %s, Author = %s, Price = %s, Quantity = %s WHERE BookID = %s"
values = [data["Title"], data["Author"], data["Price"], data["Quantity"], data["BookID"]]

# Execute the UPDATE query
cursor.execute(update_query, values)
connection.commit()

det get books from database():
cursor = connection.cursor(dictionary=True)
cursor.execute("SELECT * FROM books")
books = cursor.fetchall()
cursor.close()
return books

def get users_from_database():
cursor = connection.cursor(dictionary=T
cursor.execute("SELECT * FROM users")
users = cursor.fetchall()
cursor.close()
return users

def get carts_from database():
cursor = connection.cursor(dictionary=True)
cursor.execute("SELECT * FROM carts")
carts = cursor.fetchall()
cursor.close()
return carts

def delete book from cart(cart id):
delete query = "DELETE FROM carts WHERE CartID = %s"
cursor.execute(delete query, (cart _id,))
connection.commit()

st.title("Online Bookstore Management")

entities = ["Insert XML data","view All Tables","Delete","Update"]
selected entity = st.selectbox("Select an Option",entities)

def display entity(selected entity):

if selected entity == "View All Tables":
st.subheader( "Books ")
books = get books from_database()
st.table(books)
st.subheader(‘Users")
users = get users_from database()
st.table(users)
st.subheader( carts")
carts = get_carts_from_database()
st.table(carts)

elif selected entity == "Insert XML data":

uploaded file = st.file uploader(“Upload an XML file to insert data to the database", type=["xml"])
if uploaded_file:
insert_xml_data(uploaded file)
st.success("Data inserted successfully!")
elif selected entity == "Update":

elif selected entity == "Insert XML data":
uploaded file - st.file_uploader("upload an xu file to insert data to the database", type=["xml"])
if uploaded file:
insert_xml_data(uploaded_file)
st.success(&quot;Data inserted successfully!&quot;)
elif selected entity &quot;Update&quot;:
books = get_books_from_database()
st.table(books)
update_filest.file uploader(&quot;upload an XML file to update book details&quot;, type-[&quot;xml&quot;])
if update file:
update_book_from_xml (update_file)
st.success(&quot;Book details updated successfully!&quot;)
books get books from database()
st.table(books)
elif selected entity == &quot;Delete&quot;:
cart_id = st.number_input(&quot;Enter CartID of the book to delete&quot;, min_value=1) carts get carts_from_database()
st.table(carts)
if st.button(&quot;Delete&quot;):
delete_book_from_cart(cart_id)
st.success(&quot;Book with CartID (cart_id) deleted from the cart!&quot;)
carts = get_carts_from_database()
st.table(carts)
display_entity(selected_entity)
connection.close()
