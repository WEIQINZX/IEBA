from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, String
from sqlalchemy.orm import sessionmaker
conn_str = 'postgresql+psycopg2://postgres:wqzx110087@localhost/TEST'
engine = create_engine(conn_str)

Base = declarative_base()


class Course(Base):
    __tablename__ = 'coursearrangement'

    id = Column(Integer, primary_key=True)
    name = Column(String(20))
    year = Column(Integer)

    def __repr__(self):
        return "<Course(id='%d', name='%s', year='%d')>" % (self.id, self.name, self.year)


Base.metadata.create_all(engine)

Session = sessionmaker(bind=engine)
session = Session()
courses = [Course(name='Database', year=2021), Course(name='HFE', year=2022), Course(name='ASDA', year=2019)]
for c in courses:
    session.add(c)
session.commit()


result = engine.execute('SELECT * FROM coursearrangement')
[print(row['id'], row['name'], row['year']) for row in result]
