import com.cloudgarden.layout.AnchorLayout;
import java.awt.BorderLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JTextField;
import javax.swing.ListModel;
import javax.swing.ListSelectionModel;

import javax.swing.WindowConstants;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.SwingUtilities;
import java.io.*;

import javax.swing.DefaultComboBoxModel;

import org.w3c.dom.events.EventException;
/**
* This code was edited or generated using CloudGarden's Jigloo
* SWT/Swing GUI Builder, which is free for non-commercial
* use. If Jigloo is being used commercially (ie, by a corporation,
* company or business for any purpose whatever) then you
* should purchase a license for each developer using Jigloo.
* Please visit www.cloudgarden.com for details.
* Use of Jigloo implies acceptance of these licensing terms.
* A COMMERCIAL LICENSE HAS NOT BEEN PURCHASED FOR
* THIS MACHINE, SO JIGLOO OR THIS CODE CANNOT BE USED
* LEGALLY FOR ANY CORPORATE OR COMMERCIAL PURPOSE.
*/
public class main_frame extends javax.swing.JFrame {
	private JList item_list;
	private JButton jButton1;
	private JButton jButton8;
	private JButton jButton7;
	private JButton jButton6;
	private JButton jButton5;
	private JButton jButton4;
	private JLabel jLabel1;
	private JButton jButton3;
	private JButton jButton2;
	private String currentDirectory;
	private JLabel jLabel4;
	private JLabel jLabel5;
	private JLabel jLabel3;
	private JLabel jLabel2;
	private JButton jButton13;
	private JButton jButton12;
	private JButton jButton11;
	private JButton jButton10;
	private JButton jButton9;
	private JTextField jTextField1;
	private int list_offset;

	/**
	* Auto-generated main method to display this JFrame
	*/
 	public static void main(String[] args) 
	{
		SwingUtilities.invokeLater(new Runnable() 
		{
			public void run() 
			{
				main_frame inst = new main_frame();
				inst.setLocationRelativeTo(null);
				inst.setVisible(true);
			}
		});
	}
	
	public main_frame() {
		super();
		initGUI();
	}
	
	private void initGUI() {
		try {
			list_offset = 0;
			setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
			this.setName("kilel");
			this.setTitle("main form");
			getContentPane().setLayout(null);
			{
				currentDirectory = "/";
				File file = new File(currentDirectory);
				ListModel item_listModel = new DefaultComboBoxModel(file.list());
				item_list = new JList();
				
				getContentPane().add(item_list);
				item_list.setModel(item_listModel);
				item_list.setBounds(13, 12, 276, 272);
				item_list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
				item_list.setDropMode(javax.swing.DropMode.USE_SELECTION);
				item_list.setVisibleRowCount(80);
				item_list.setAutoscrolls(true);
				item_list.addListSelectionListener(new ListSelectionListener() {
					public void valueChanged(ListSelectionEvent evt) {
						item_listValueChanged(evt);
					}
				});
			}
			{
				jButton1 = new JButton();
				getContentPane().add(jButton1);
				jButton1.setText("/");
				jButton1.setBounds(301, 12, 53, 22);
				jButton1.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton1MouseClicked(evt);
					}
				});
			}
			{
				jButton2 = new JButton();
				getContentPane().add(jButton2);
				jButton2.setText("go deeper");
				jButton2.setBounds(301, 45, 108, 26);
				jButton2.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton2MouseClicked(evt);
					}
				});
			}
			{
				jButton3 = new JButton();
				getContentPane().add(jButton3);
				jButton3.setText("go back");
				jButton3.setBounds(301, 82, 108, 22);
				jButton3.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton3MouseClicked(evt);
					}
				});
			}
			{
				jLabel1 = new JLabel();
				getContentPane().add(jLabel1);
				jLabel1.setText("/");
				jLabel1.setBounds(12, 296, 371, 15);
			}
			{
				jButton4 = new JButton();
				getContentPane().add(jButton4);
				jButton4.setText("Create folder");
				jButton4.setBounds(427, 12, 143, 22);
				jButton4.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton4MouseClicked(evt);
					}
				});
			}
			{
				jButton5 = new JButton();
				getContentPane().add(jButton5);
				jButton5.setText("create file");
				jButton5.setBounds(427, 47, 143, 22);
				jButton5.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton5MouseClicked(evt);
					}
				});
			}
			{
				jButton6 = new JButton();
				getContentPane().add(jButton6);
				jButton6.setText("delete");
				jButton6.setBounds(427, 82, 143, 22);
				jButton6.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton6MouseClicked(evt);
					}
				});
			}
			{
				jButton7 = new JButton();
				getContentPane().add(jButton7);
				jButton7.setText("prev");
				jButton7.setBounds(301, 155, 108, 22);
				jButton7.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton7MouseClicked(evt);
					}
				});
			}
			{
				jButton8 = new JButton();
				getContentPane().add(jButton8);
				jButton8.setText("next");
				jButton8.setBounds(301, 188, 108, 22);
				jButton8.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton8MouseClicked(evt);
					}
				});
			}
			{
				jTextField1 = new JTextField();
				getContentPane().add(jTextField1);
				jTextField1.setBounds(427, 155, 291, 22);
			}
			{
				jButton9 = new JButton();
				getContentPane().add(jButton9);
				jButton9.setText("copy to");
				jButton9.setBounds(427, 188, 148, 22);
				jButton9.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						try{
							jButton9MouseClicked(evt);
						} 
						catch(IOException e)
						{
							;
						}
					}
				});
			}
			{
				jButton10 = new JButton();
				getContentPane().add(jButton10);
				jButton10.setText("move to");
				jButton10.setBounds(427, 221, 148, 22);
				jButton10.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton10MouseClicked(evt);
					}
				});
			}
			{
				jButton11 = new JButton();
				getContentPane().add(jButton11);
				jButton11.setText("rename to");
				jButton11.setBounds(427, 254, 148, 22);
				jButton11.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton11MouseClicked(evt);
					}
				});
			}
			{
				jButton12 = new JButton();
				getContentPane().add(jButton12);
				jButton12.setText("make RO");
				jButton12.setBounds(586, 188, 133, 22);
				jButton12.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton12MouseClicked(evt);
					}
				});
			}
			{
				jButton13 = new JButton();
				getContentPane().add(jButton13);
				jButton13.setText("make not RO");
				jButton13.setBounds(586, 221, 133, 22);
				jButton13.addMouseListener(new MouseAdapter() {
					public void mouseClicked(MouseEvent evt) {
						jButton13MouseClicked(evt);
					}
				});
			}
			{
				jLabel2 = new JLabel();
				getContentPane().add(jLabel2);
				jLabel2.setText("is hidden?");
				jLabel2.setBounds(586, 257, 132, 15);
			}
			{
				jLabel3 = new JLabel();
				getContentPane().add(jLabel3);
				jLabel3.setText("RO?");
				jLabel3.setBounds(586, 277, 132, 15);
			}
			{
				jLabel4 = new JLabel();
				getContentPane().add(jLabel4);
				jLabel4.setText("size of file");
				jLabel4.setBounds(586, 296, 132, 15);
			}
			{
				jLabel5 = new JLabel();
				getContentPane().add(jLabel5);
				jLabel5.setText("free space");
				jLabel5.setBounds(427, 296, 153, 15);
			}
			pack();
			this.setSize(740, 347);
		} catch (Exception e) {
		    //add your error handling code here
			e.printStackTrace();
			
		}
	}
	
	private void jButton1MouseClicked(MouseEvent evt) 
	{
		currentDirectory = "/";
		jLabel1.setText(currentDirectory);
		File file = new File(currentDirectory);
		ListModel item_listModel = new DefaultComboBoxModel(file.list());
		item_list.setModel(item_listModel);
	}
	
	private void jButton2MouseClicked(MouseEvent evt) {
		//System.out.println("jButton2.mouseClicked, event="+evt);
		//TODO add your code for jButton2.mouseClicked
		if(!item_list.isSelectionEmpty())
		{
			int i = item_list.getSelectedIndices()[0];
			File file = new File(currentDirectory + "/" + item_list.getModel().getElementAt(i).toString());
			if(file.isDirectory())
			{
				currentDirectory +=  "/" + item_list.getModel().getElementAt(i).toString();
				jLabel1.setText(currentDirectory);
				item_list.setModel(new DefaultComboBoxModel(file.list()));
			}
		}
			
	}
	
	private void jButton3MouseClicked(MouseEvent evt) 
	{
		//System.out.println("jButton3.mouseClicked, event="+evt);
		//TODO add your code for jButton3.mouseClicked
		if(currentDirectory.length() > 1)
		{
			File file = new File(currentDirectory);
			currentDirectory = file.getParent();
			jLabel1.setText(currentDirectory);
			file = new File(currentDirectory);
			item_list.setModel(new DefaultComboBoxModel(file.list()));
		}
	}
	
	
	
	private void jButton4MouseClicked(MouseEvent evt) {
		//System.out.println("jButton4.mouseClicked, event="+evt);
		//TODO add your code for jButton4.mouseClicked
		File file;
		file = new File(currentDirectory + "/NewFolder");
		if(file.exists())
		{
			for(int i = 1; i < 99999; i++)
				{
					file = new File(currentDirectory + "/NewFolder_" + i);
					if(!file.exists())
						break;
				}
		}
		
		file.mkdirs();
		file = file.getParentFile();
		item_list.setModel(new DefaultComboBoxModel(file.list()));
		
	}
	
	private void jButton5MouseClicked(MouseEvent evt) {
		//System.out.println("jButton5.mouseClicked, event="+evt);
		//TODO add your code for jButton5.mouseClicked
		File file;
		file = new File(currentDirectory + "/NewFile");
		if(file.exists())
		{
			for(int i = 1; i < 99999; i++)
				{
					file = new File(currentDirectory + "/NewFile_" + i);
					if(!file.exists())
						break;
				}
		}
		try
		{
			file.createNewFile();
		}
		catch(Exception e)
		{
			return;
		}
		
		file = file.getParentFile();
		item_list.setModel(new DefaultComboBoxModel(file.list()));
	}
	
	private void jButton7MouseClicked(MouseEvent evt) {
		//System.out.println("jButton7.mouseClicked, event="+evt);
		//TODO add your code for jButton7.mouseClicked
		File file = new File(currentDirectory);
		String s[] = new String[16];
		if(list_offset > 0)
		{
			list_offset -= 16;
			for(int i = 0; i < 16 && (i + list_offset) < file.list().length; i++)
				s[i] = file.list()[i+list_offset]; 
			item_list.setModel(new DefaultComboBoxModel(s));
		}
		
	}
	
	private void jButton8MouseClicked(MouseEvent evt) {
		//System.out.println("jButton8.mouseClicked, event="+evt);
		//TODO add your code for jButton8.mouseClicked
		File file = new File(currentDirectory);
		String s[] = new String[16];
		if(list_offset+16 < file.list().length)
		{
			list_offset += 16;
			for(int i = 0; i < 16 && (i + list_offset) < file.list().length; i++)
				s[i] = file.list()[i+list_offset]; 
			item_list.setModel(new DefaultComboBoxModel(s));
		}
		
	}

	private void jButton6MouseClicked(MouseEvent evt) {
		//Delete function
		//System.out.println("jButton6.mouseClicked, event="+evt);
		//TODO add your code for jButton6.mouseClicked
		if(!item_list.isSelectionEmpty())
		{
			int i = item_list.getSelectedIndices()[0];
			File file = new File(currentDirectory + "/" + item_list.getModel().getElementAt(i).toString());
			if(file.isDirectory())
				deleteFolder(file);
			else
				file.delete();
			file = new File(currentDirectory);
			item_list.setModel(new DefaultComboBoxModel(file.list()));
		}
		
	}
	
	private void deleteFolder(File f)
	{
		File filelist[] = f.listFiles();
		for(int i = 0; i < filelist.length; i++)
			if(filelist[i].isFile())
				filelist[i].delete();
		filelist = f.listFiles();
		if(f.list().length > 0)
			for(int i = 0; i < filelist.length; i++)
				deleteFolder(filelist[i]);
		f.delete();
	}
	
	private void item_listValueChanged(ListSelectionEvent evt) {
		//выбрали другой элемент
		if(!item_list.isSelectionEmpty())
		{
			int i = item_list.getSelectedIndices()[0];
			File file = new File(currentDirectory + "/" + item_list.getModel().getElementAt(i).toString());
			if(file.isHidden())
				jLabel2.setText("Hidden");
			else
				jLabel2.setText("Not hidden");
			if(file.canWrite())
				jLabel3.setText("Not RO");
			else
				jLabel3.setText("RO");
			if(file.isFile())
				jLabel4.setText("File");
			else
				jLabel4.setText("Folder");
			jLabel5.setText(file.getFreeSpace()/1000000 + " Mb");
		}
	}
	
	private void jButton9MouseClicked(MouseEvent evt) throws IOException {
		//System.out.println("jButton9.mouseClicked, event="+evt);
		//TODO add your code for jButton9.mouseClicked copy
		if(!item_list.isSelectionEmpty())
		{
			int i = item_list.getSelectedIndices()[0];
			File file = new File(currentDirectory + "/" + item_list.getModel().getElementAt(i).toString());
			if(file.isFile())
			{
				File newFile = new File(jTextField1.getText() + "/" + item_list.getModel().getElementAt(i).toString());
				if(!newFile.exists())
					{
						try
						{
							newFile.createNewFile();
						    FileReader in = new FileReader(file);
						    FileWriter out = new FileWriter(newFile);
						    int c;
						    while ((c = in.read()) != -1)
						      out.write(c);
						    in.close();
						    out.close();
						}
						catch(EventException e)
						{
							;
						}
					}
				file = new File(currentDirectory);
				item_list.setModel(new DefaultComboBoxModel(file.list()));
				
			}
			
		}
	}
	
	private void jButton12MouseClicked(MouseEvent evt) {
		//System.out.println("jButton12.mouseClicked, event="+evt);
		//TODO add your code for jButton12.mouseClicked mk ro
		if(!item_list.isSelectionEmpty())
		{
			int i = item_list.getSelectedIndices()[0];
			File file = new File(currentDirectory + "/" + item_list.getModel().getElementAt(i).toString());
			file.setReadOnly();
		}
	}
	
	private void jButton13MouseClicked(MouseEvent evt) {
		//System.out.println("jButton13.mouseClicked, event="+evt);
		//TODO add your code for jButton13.mouseClicked mk not ro
		if(!item_list.isSelectionEmpty())
		{
			int i = item_list.getSelectedIndices()[0];
			File file = new File(currentDirectory + "/" + item_list.getModel().getElementAt(i).toString());
			file.setWritable(true);
		}
	}
	
	private void jButton11MouseClicked(MouseEvent evt) {
		//System.out.println("jButton11.mouseClicked, event="+evt);
		//TODO add your code for jButton11.mouseClicked rename
		if(!item_list.isSelectionEmpty())
		{
			int i = item_list.getSelectedIndices()[0];
			File file = new File(currentDirectory + "/" + item_list.getModel().getElementAt(i).toString());
			String s = jTextField1.getText();
			if(s.length() > 0)
				file.renameTo(new File(currentDirectory + "/" + s));
			file = new File(currentDirectory);
			item_list.setModel(new DefaultComboBoxModel(file.list()));
		}
	}
	
	private void jButton10MouseClicked(MouseEvent evt) {
		//System.out.println("jButton10.mouseClicked, event="+evt);
		//TODO add your code for jButton10.mouseClicked  move to
		if(!item_list.isSelectionEmpty())
		{
			int i = item_list.getSelectedIndices()[0];
			File file = new File(currentDirectory + "/" + item_list.getModel().getElementAt(i).toString());
			File newFolder = new File(jTextField1.getText());
			if(newFolder.exists() && newFolder.isDirectory())
				file.renameTo(new File(jTextField1.getText() + "/" + item_list.getModel().getElementAt(i).toString()));
			file = new File(jTextField1.getText());
			item_list.setModel(new DefaultComboBoxModel(file.list()));
		}
	}
}

