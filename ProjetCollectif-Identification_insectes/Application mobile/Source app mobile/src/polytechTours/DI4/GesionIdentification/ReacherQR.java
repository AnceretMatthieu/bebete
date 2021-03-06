package polytechTours.DI4.GesionIdentification;

import java.io.File;
import java.io.IOException;
import java.util.Vector;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import polytechTours.DI4.R;


import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Environment;
import android.util.Log;
import android.widget.ImageView;

/**
 * @author Julien Teruel
 * Classe permettant de parser le fichier XML d'entr�e en d'en g�n�rer toutes les questions, r�ponses ainsi que leur arborescence
 * Utiliser par QuestionFramgent pour obtenir la r�ponse de Base et naviguer entre les questions
 */
public class ReacherQR 
{
	private DocumentBuilderFactory factory;
	private DocumentBuilder builder;
	private Document dom;
	private Element root;
	private Vector<Question> listQuestion = new Vector<Question>();
	
	public ReacherQR()
	{	
		File fichierXML = new File( FileManager.getSavePath() + File.separator + "accueil.xml" );
		factory = DocumentBuilderFactory.newInstance();
		
		try 
		{
			builder = factory.newDocumentBuilder();
			try 
			{
				dom = builder.parse(fichierXML);
				root = dom.getDocumentElement();
				NodeList items = root.getElementsByTagName( "question" ); //listes des questions
				
				for( int i = 0; i < items.getLength(); i++ )             //Je parcours toutes les questions
				{
					Question question = new Question();
					
					NamedNodeMap attrs = items.item(i).getAttributes();   //liste des attributs par question
					
					for( int j = 0 ; j < attrs.getLength(); j++ )
					{
						Node node1 = attrs.item(j);
						
						if( node1.getNodeName().equalsIgnoreCase("id") )
						{
							question.setId( node1.getTextContent() );
						}
						else if( node1.getNodeName().equalsIgnoreCase("texte") )
						{
							question.setQuestion( node1.getTextContent() );
						}
						else if( node1.getNodeName().equalsIgnoreCase("observation") )
						{
							if( node1.getTextContent().equalsIgnoreCase("oeil") )
							{
								question.setVignette( Question.OEIL );
							}
							else if( node1.getTextContent().equalsIgnoreCase("loupe") )
							{
								question.setVignette( Question.LOUPE );
							}
							else if( node1.getTextContent().equalsIgnoreCase("both") )
							{
								question.setVignette( Question.BOTH );
							}
						}
					}
				
					NodeList list = items.item(i).getChildNodes();
					
					for (int j = 0; j < list.getLength(); j++ )
					{
						if( list.item(j).getNodeName().equalsIgnoreCase("media") ) //Traitement des medias relatif � la question
						{
							Node media = list.item(j);
							NodeList medias = media.getChildNodes();
							
							for( int k = 0; k < medias.getLength(); k++ )
							{
								if( medias.item(k).getNodeName().equalsIgnoreCase("legende") )
								{
									question.setAide( medias.item(k).getTextContent() );
								}
								else if( medias.item(k).getNodeName().equalsIgnoreCase("img") )
								{
									NamedNodeMap attrs2 = medias.item(k).getAttributes();
									for( int p = 0; p < attrs2.getLength(); p++ )
									{
										if( attrs2.item(p).getNodeName().equals("src") )
										{
											question.setCheminImage( attrs2.item(p).getTextContent() );
										}
									}
								}
							}
						}
						else if( list.item(j).getNodeName().equalsIgnoreCase("reponse") )  //Traitement des reponses � la question
						{
							Reponse reponse = new Reponse();
							Node rep = list.item(j);
							
							NamedNodeMap attrs2 = rep.getAttributes();
							
							for( int p = 0; p < attrs2.getLength(); p++ )  //recuperation des attributs par reponses
							{
								if( attrs2.item(p).getNodeName().equals("id") )
								{
									Log.d("XML parsing", "Id reponse : " + attrs2.item(p).getTextContent() );
									reponse.setId( attrs2.item(p).getTextContent() );
								}
								else if( attrs2.item(p).getNodeName().equalsIgnoreCase( "texte" ) )
								{
									Log.d("XML parsing", "Texte reponse :" + attrs2.item(p).getTextContent() );
									reponse.setReponse( attrs2.item(p).getTextContent() );
								}
							}
							
							NodeList nodes = rep.getChildNodes();
							
							for( int p = 0; p < nodes.getLength(); p++ )  //recuperation des medias par reponses
							{
								if( nodes.item(p).getNodeName().equalsIgnoreCase("media") )
								{
									NodeList medias = nodes.item(p).getChildNodes();
									
									for( int u = 0; u < medias.getLength(); u++ )
									{
										if( medias.item(u).getNodeName().equalsIgnoreCase( "img" ) )
										{
											NamedNodeMap attrs3 = medias.item(u).getAttributes();
											for( int o = 0; o < attrs3.getLength(); o++ )
											{
												if( attrs3.item(o).getNodeName().equals("src") &&  attrs3.item(o).getTextContent() != null )
												{
													Log.d("XML parsing", "Img rep :" + attrs3.item(o).getTextContent() );
													reponse.getListeImage().add( attrs3.item(o).getTextContent() );
												}
											}
										}
										else if( medias.item(u).getNodeName().equalsIgnoreCase( "legende" ) )
										{
											reponse.setLegende(medias.item(u).getTextContent());
											Log.d("XML parsing", "Legende rep :" + medias.item(u).getTextContent() );
										}
									}
								}
								else if( nodes.item(p).getNodeName().equalsIgnoreCase( "question" ) )
								{
									Log.d("XML parsing", "Je detecte une question suivante" );
									NamedNodeMap attr3 = nodes.item(p).getAttributes();
									
									for( int o = 0; o < attr3.getLength(); o++ )
									{
										if( attr3.item(o).getNodeName().equalsIgnoreCase("id") )
										{
											reponse.setIdQuestionSuivante( attr3.item(o).getTextContent() );
											Log.d("XML parsing", "id question suivante :" + reponse.getIdQuestionSuivante() );
										}
									}
								}
								else if( nodes.item(p).getNodeName().equalsIgnoreCase( "branche" ) )
								{
									Node branche = nodes.item(p);
									NodeList nodesBranche = branche.getChildNodes();
									
									for( int u = 0; u < nodesBranche.getLength(); u++ )
									{
										if( nodesBranche.item(u).getNodeName().equalsIgnoreCase( "question" ) )
										{
											Log.d("XML parsing", "Je detecte une question suivante" );
											NamedNodeMap attr3 = nodesBranche.item(u).getAttributes();
											
											for( int o = 0; o < attr3.getLength(); o++ )
											{
												if( attr3.item(o).getNodeName().equalsIgnoreCase("id") )
												{
													reponse.setIdQuestionSuivante( attr3.item(o).getTextContent() );
													Log.d("XML parsing", "id question suivante :" + reponse.getIdQuestionSuivante() );
												}
											}
										}
									}
								}
								else if( nodes.item(p).getNodeName().equalsIgnoreCase( "resultat" ) )
								{
									Resultat resultat = new Resultat();
									NamedNodeMap attr3 = nodes.item(p).getAttributes();
									
									for( int o = 0; o < attr3.getLength(); o++ )
									{
										if( attr3.item(o).getNodeName().equalsIgnoreCase("id") )
										{
											resultat.setId( attr3.item(o).getTextContent() );
										}
									}
									
									NodeList nodesResultat = nodes.item(p).getChildNodes();
									
									for( int o = 0; o < nodesResultat.getLength(); o++ )
									{
										if( nodesResultat.item(o).getNodeName().equalsIgnoreCase("nom") )
										{
											resultat.setNom( nodesResultat.item(o).getTextContent() );
										}
										else if( nodesResultat.item(o).getNodeName().equalsIgnoreCase("type") )
										{
											resultat.setType(nodesResultat.item(o).getTextContent());
										}
										else if( nodesResultat.item(o).getNodeName().equalsIgnoreCase("regimeAlimentaire") )
										{
											resultat.setRegimeAlimentaire(nodesResultat.item(o).getTextContent());
										}
										else if( nodesResultat.item(o).getNodeName().equalsIgnoreCase("informations") )
										{
											resultat.setInformation(nodesResultat.item(o).getTextContent());
										}
										else if( nodesResultat.item(o).getNodeName().equalsIgnoreCase("media") )
										{
											NodeList nodeImage = nodesResultat.item(o).getChildNodes();
											
											for( int u = 0; u < nodeImage.getLength(); u++ )
											{
												if( nodeImage.item(u).getNodeName().equalsIgnoreCase("img") )
												{
													NamedNodeMap attrs3 = nodeImage.item(u).getAttributes();
													for( int k = 0; k < attrs3.getLength(); k++ )
													{
														if( attrs3.item(k).getNodeName().equals("src") &&  attrs3.item(k).getTextContent() != null )
														{
															Log.d("XML parsing", "Img rep :" + attrs3.item(k).getTextContent() );
															resultat.getListeImage().add(attrs3.item(k).getTextContent() );
														}
													}
												}
											}
										}
									}
									reponse.setResultat(resultat);
								}
							}
							question.getListReponse().add(reponse);
						}
					}
					listQuestion.add(question);
				}
				
			} 
			catch (SAXException e) 
			{
				Log.d("XML parsing", "Erreur SAX " + e.getLocalizedMessage() );
			} 
			catch (IOException e) 
			{
				Log.d("XML parsing", "Erreur IO" );
			}
		} 
		catch (ParserConfigurationException e)
		{
			Log.d("XML parsing", "Erreur de configuration" );
		}
	
	}

	public Question getQuestionRoot()
	{
		return listQuestion.firstElement();
	}
	
	public Question findQuestionById( String id )
	{
		for( int i = 0; i < listQuestion.size(); i++ )
		{
			if( listQuestion.get(i).getId() == id )
			{
				return listQuestion.get(i);
			}
		}
		return null;
	}
	
	public Vector<String> listeImageResultat()
	{
		Vector<Resultat> listResultat = new Vector<Resultat>();
		
		for(int i = 0; i < listQuestion.size(); i++ )
		{
			Vector<Reponse> listReponse = listQuestion.get(i).getListReponse();
			
			for( int j = 0; j < listReponse.size(); j++ )
			{
				if( listReponse.get(j).getResultat() != null )
				{
					listResultat.add( listReponse.get(j).getResultat() );
				}
			}
		}
		
		Vector<String>listResult = new Vector<String>();
		
		for( int i = 0; i < listResultat.size(); i++ )
		{
			Vector<String> listChemin = listResultat.get(i).getListeImage();
			
			for( int j = 0; j < listChemin.size(); j++ )
			{
				listResult.add(listChemin.get(j) );			
			}
		}
		return listResult;
	}
	
	public Resultat getResultatFomImage( String cheminImage )
	{
		Vector<Resultat> listResultat = new Vector<Resultat>();
		
		for(int i = 0; i < listQuestion.size(); i++ )
		{
			Vector<Reponse> listReponse = listQuestion.get(i).getListReponse();
			
			for( int j = 0; j < listReponse.size(); j++ )
			{
				if( listReponse.get(j).getResultat() != null  )
				{
					listResultat.add( listReponse.get(j).getResultat() );
				}
			}
		}

		for( int i = 0; i < listResultat.size(); i++ )
		{
			Vector<String> listChemin = listResultat.get(i).getListeImage();
			
			for( int j = 0; j < listChemin.size(); j++ )
			{
				Log.d("Comparaison", "Comp : " + listChemin.get(j) + " " + cheminImage );
				if( listChemin.get(j).equalsIgnoreCase( cheminImage ) )
				{
					return listResultat.get(i);
				} 
			}
		}
		return null;
	}
	
	
}
