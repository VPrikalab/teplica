import telebot
token ='225829342:AAFoaGLUlvz2DBRC-yO7-bS9nw8UC9vMDCs'
Father_id=115491916
Brother_id=232235986
Anton= telebot.TeleBot(token)
def response_message(text):

	Anton.send_message(Father_id,text)
